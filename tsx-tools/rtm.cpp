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

int myabort = 0;
int succ = 0;

int print_flag = 0;  /* flag used to control the printer */
int cleaner_flag = 0;
int shooting_flag = 0;

struct timeval start;
struct timeval new_start;

void ShooterAction(int rate,Color PlayerColor){
    int suc = 0;
    int nretries=0;
    int status;
    
    struct timeval finish;
    int time_passed;
    int successful_shot = 0; /* The time successfully get a shot */
    int r_lane; /* Random lane number 1*/
    int r_lane_flag = 0;
    
    #ifdef ROGUETM
    while(1){
        gettimeofday(&finish, 0);
        time_passed = (finish.tv_sec - start.tv_sec) * 1000000 + finish.tv_usec - start.tv_usec;
        if(time_passed % (1000000/rate) != 0){
            continue;
        }else{
            ;
        }
        /* Try get a lane */
        /* r_lane is the lane */
        r_lane = rand()%lane_number;
        
        /* Check if the lane is white */
        Color this_color = Gallery->Get(r_lane);
        
        //cout<<"Player"<<PlayerColor<<" get into the transaction"<<endl;
        
        /* Shoot the lane if the lane is white*/
        if(this_color == white&&!cleaner_flag){
            if ((status = _xbegin ()) == _XBEGIN_STARTED) {
                suc++;
                Gallery->Set(r_lane,PlayerColor);
                shooting_flag = 0;
                successful_shot++;
                _xend ();
            }else{
                nretries++;
            }
        }else{
            r_lane_flag++;
            if(r_lane_flag >= lane_number/2){
                int j = 0;
                for(j = 0; j < lane_number; j++){
                    if(Gallery->Get(j) == white){
                        break;
                    }
                }
                if(j == lane_number){
                    if ((status = _xbegin ()) == _XBEGIN_STARTED) {
                        suc++;
                        succ = suc;
                        myabort = nretries;
                        suc = 0;
                        nretries = 0;
                        print_flag = 1;
                        _xend ();
                    }else{
                        nretries++;
                    }
                }
                
            }
        }
    }
    #endif
    #ifdef ROGUETM2
    int r_lane_2; /* Random lane number 2*/
    while(1){
        gettimeofday(&finish, 0);
        time_passed = (finish.tv_sec - start.tv_sec) * 1000000 + finish.tv_usec - start.tv_usec;
        if(time_passed % (1000000/rate) != 0){
            continue;
        }else{
            ;
        }
        /* Try get a lane */
        /* r_lane is the lane */
        r_lane = rand()%lane_number;
        r_lane_2 = rand()%lane_number;
        while(r_lane == r_lane_2){
            r_lane_2 = rand()%lane_number;
        }
        
        /* Check if the lane is white */
        Color this_color = Gallery->Get(r_lane);
        Color this_color_2 = Gallery->Get(r_lane_2);
        
        //cout<<"Player"<<PlayerColor<<" get into the transaction"<<endl;
        
        /* Shoot the lane if the lane is white*/
        if(this_color == white&&this_color_2 == white&&!cleaner_flag){
            if ((status = _xbegin ()) == _XBEGIN_STARTED) {
                suc++;
                Gallery->Set(r_lane,PlayerColor);
                Gallery->Set(r_lane_2,PlayerColor);
                shooting_flag = 0;
                successful_shot++;
                _xend ();
            }else{
                nretries++;
            }
        }else{
            r_lane_flag++;
            if(r_lane_flag >= lane_number/2){
                int j = 0;
                for(j = 0; j < lane_number; j++){
                    if(Gallery->Get(j) == white){
                        break;
                    }
                }
                if(j == lane_number){
                    if ((status = _xbegin ()) == _XBEGIN_STARTED) {
                        suc++;
                        succ = suc;
                        myabort = nretries;
                        suc = 0;
                        nretries = 0;
                        print_flag = 1;
                        _xend ();
                    }else{
                        nretries++;
                    }
                }
                
            }
        }
        
    }
    #endif
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
    while(1){
        if(cleaner_flag == 1){
            int i;
            for(i = 0; i < lane_number; i++){
                if(Gallery->Get(i) == white){
                    break;
                }
            }
            if(i >= lane_number){
                Gallery->Clear();
            }
            cleaner_flag = 0;
        }
    }
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
    struct timeval finish;
    double total_time_passed = 0;
    int time_passed;
    int red_sum = 0;
    int blue_sum = 0;
    int round_num = round;
    while(1){
        if(print_flag == 1){
            gettimeofday(&finish, 0);
            time_passed = (finish.tv_sec - new_start.tv_sec) * 1000000 + finish.tv_usec - new_start.tv_usec;
            cout<<"Printer in working "<<round<<endl;
            for(int i = 0; i < lane_number; i++){
                if(Gallery->Get(i) == red){
                    red_sum++;
                }
                if(Gallery->Get(i) == blue){
                    blue_sum++;
                }
            }
            cout<<"Red shoot rate: "<<red_sum*1000000*1.0/time_passed<<endl;
            cout<<"Blue shoot rate: "<<blue_sum*1000000*1.0/time_passed<<endl;
            cout<<"Total time used: "<<time_passed<<endl;
            cout<<"Abort rate: "<<myabort*1.0/(succ + myabort)<<endl;
            total_time_passed += time_passed;
            red_sum = 0;
            blue_sum = 0;
            Gallery->Print();
            gettimeofday(&new_start, 0);
            print_flag = 0;
            #ifndef ROGUETMCLEANER
            Gallery->Clear();
            #endif
            #ifdef ROGUETMCLEANER
            cleaner_flag = 1;
            while(cleaner_flag);
            #endif
            if(round == 1){
                cout<<"Time used: "<<total_time_passed<<endl;
                cout<<"Average time used: "<<total_time_passed/round_num<<endl;
            }
            round--;
        }
        if(round == 0){
            exit(0);
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
    gettimeofday(&new_start, 0);
    ths.push_back(std::thread(&ShooterAction,red_rate,red));
    ths.push_back(std::thread(&ShooterAction,blue_rate,blue));
    ths.push_back(std::thread(&Cleaner));
    ths.push_back(std::thread(&Printer));


    for (auto& th : ths) {
        th.join();
    }

    return 0;
}
