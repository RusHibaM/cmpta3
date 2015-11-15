#include <immintrin.h>
#include <iostream>
#include <vector>
#include <thread>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include "Lanes.h"
using namespace std;

int counter;

Lanes* Gallery;
int nlanes;

int red_rate;
int blue_rate;
int round;
int lane_number;

int print_flag = 0;  /* flag used to control the printer */

struct timeval start;

void ShooterAction(int rate,Color PlayerColor){
    int nretries=0;
    int status;
    
    struct timeval finish;
    int time_passed;
    int successful_shot = 0; /* The time successfully get a shot */
    int r_lane; /* Random lane number 1*/
    int r_lane_flag = 0;
    int cleaner_flag = 0;
    
    while(1){
        gettimeofday(&finish, 0);
        time_passed = (finish.tv_sec - start.tv_sec) * 1000000 + finish.tv_usec - start.tv_usec;
        if(time_passed % (1000000/rate) != 0){
            continue;
        }else{
            ;
        }
        if ((status = _xbegin ()) == _XBEGIN_STARTED) {
            counter++;
            /* Try get a lane */
            /* r_lane is the lane */
            r_lane = rand()%lane_number;
            cout<<"Player"<<PlayerColor<<" get into the transaction"<<endl;
            
            /* Check if the lane is white */
            Color this_color = Gallery->Get(r_lane);
            /* Shoot the lane if the lane is white*/
            if(this_color == white&&!cleaner_flag){
                cout<<"Player"<<PlayerColor<<" ready to shoot to "<<r_lane<<endl;
                Gallery->Set(r_lane,PlayerColor);
                successful_shot++;
                _xend ();
            }else{
                cout<<"Player"<<PlayerColor<<" fail to shoot to "<<r_lane<<endl;
                r_lane_flag++;
                if(r_lane_flag >= lane_number/2){
                    r_lane_flag = 0;
                    #ifndef ROGUETMCLEANER
                    cleaner_flag = 1;
                    int j;
                    for(j = 0; j < lane_number; j++){
                        if(Gallery->Get(j) == white){
                            break;
                        }
                    }
                    if(j == lane_number){
                        print_flag = 1;
                        while(print_flag);
                        round--;
                        if(round == 0){
                            exit(0);
                        }
                        sleep(1);
                        Gallery->Clear();
                        _xend ();
                        cleaner_flag = 0;
                    }else{
                        cleaner_flag = 0;
                        _xend ();
                    }
                    #endif
                    #ifdef ROGUETMCLEANER
                    cleaner_flag = 1;
                    while(cleaner_flag);
                    #endif
                }
            }
            _xend ();
        }else{
            nretries++;
        }
        cout<<"Status is "<<status<<endl;
        cout<<"This the "<<nretries<<"th try."<<endl;
    }
}

void Cleaner()
{
    
    /**
     *  Cleans up lanes. Needs to synchronize with shooter.
     *  Use a monitor
     *  Should be in action only when all lanes are shot.
     *  Once all lanes are shot. Cleaner starts up.
     *  Once cleaner starts up shooters wait for cleaner to finish.
     */
//    while(1){
//        if(cleaner_flag == 1){
//            int i;
//            for(i = 0; i < lane_number; i++){
//                if(Gallery->Get(i) == white){
//                    break;
//                }
//            }
//            if(i >= lane_number){
//                print_flag = 1;
//                while(print_flag);
//                round--;
//                if(round == 0){
//                    exit(0);
//                }
//                sleep(1);
//                cout<<"Rogue Coarse Cleaner in working"<<endl;
//                cout<<endl;
//                Gallery->Clear();
//            }
//            cleaner_flag = 0;
//        }
//    }
}


void Printer()
{
    
    /**
     *  NOT TRANSACTION SAFE; cannot be called inside a transaction. Possible conflict with other Txs Performs I/O
     *  Print lanes periodically rate/s.
     *  If it doesn't synchronize then possible mutual inconsistency between adjacent lanes.
     *  Not a particular concern if we don't shoot two lanes at the same time.
     *
     */
    while(1){
        if(print_flag == 1){
            cout<<"Printer in working"<<endl;
            Gallery->Print();
            print_flag = 0;
        }
    }
}

int main(int argc, char** argv)
{

    counter = 0;

    vector<thread> ths;
    
    char temp;
    if(argc==1)
    {
        std::cout<<"Invalid input, please check the readme file to get more information"<<std::endl;
        exit(1);
    }
    
    while((temp=getopt(argc,argv,"r:b:n:l"))!=-1)
    {
        switch (temp)
        {
            case 'r':
                red_rate = atoi(argv[2]);
                break;
            case 'b':
                blue_rate = atoi(argv[4]);
                break;
            case 'n':
                round = atoi(argv[6]);
                break;
            case 'l':
                lane_number = atoi(argv[8]);
                break;
        }
    }
    
    cout<<"Red rate set to: "<<red_rate<<endl;
    cout<<"Blue rate set to: "<<blue_rate<<endl;
    cout<<"Round set to: "<<round<<endl;
    cout<<"Number of lanes set to: "<<lane_number<<endl;
    
    Gallery = new Lanes(lane_number);
    
    gettimeofday (&start, NULL);
    ths.push_back(std::thread(&ShooterAction,red_rate,red));
    ths.push_back(std::thread(&ShooterAction,blue_rate,blue));
    ths.push_back(std::thread(&Cleaner));
    ths.push_back(std::thread(&Printer));


    for (auto& th : ths) {
        th.join();
    }

    return 0;
}
