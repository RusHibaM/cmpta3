#include <iostream>
#include <thread>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include "Lanes.h"
#include "Rogue.h"
#include <vector>

Lanes* Gallery;
int nlanes;

int red_rate;
int blue_rate;
int round;
int lane_number;

int print_flag = 0;  /* flag used to control the printer */

struct timeval start;

#ifdef ROGUECOARSE

My_Lock coarseLock;

int cleaner_flag = 0;/* flag used to control the cleaner */

int coarse_lock = 0;

#endif

using namespace std;

void ShooterAction(int rate,Color PlayerColor)
{
#ifdef ROGUECOARSE
    
    struct timeval finish;
    #ifdef LOCKFIRST
    int time_passed;
    int successful_shot = 0; /* The time successfully get a shot */
    int r_lane; /* Random lane number */
    int r_lane_flag = 0;
    while(1){
        gettimeofday(&finish, 0);
        time_passed = (finish.tv_sec - start.tv_sec) * 1000000 + finish.tv_usec - start.tv_usec;
        if(time_passed % (1000000/rate) != 0){
            continue;
        }else{
            ;
        }
        while(cleaner_flag);/* Another thread is working as a cleaner */
        /* Try acquire the lock */
        if(!coarseLock.check_lock()&&!cleaner_flag){
            //cout<<"1Player"<<PlayerColor<<endl;
            /* Double check to gaurantee the synchronization */
            if (coarseLock.set_lock()&&!cleaner_flag) {
                cout<<"Player"<<PlayerColor<<" gets the lock"<<endl;
                /* Try get a lane */
                /* r_lane is the lane */
                r_lane = rand()%lane_number;
                cout<<"The lane_number: "<<lane_number<<endl;
                cout<<"Get random lane number: "<<r_lane<<endl;
                
                
                /* Check if the lane is white */
                Color this_color = Gallery->Get(r_lane);
                
                /* Shoot the lane if the lane is white*/
                if(this_color == white&&!cleaner_flag){
                    
                    
                    cout<<"Ready to shoot to lane: "<<r_lane<<endl;
                    
                    
                    Gallery->Set(r_lane,PlayerColor);
                    successful_shot++;
                    coarseLock.release_lock();
                }else{
                    r_lane_flag++;
                    if(r_lane_flag >= lane_number/2){
                        
                        
                        cout<<"Try clean with flag: "<<r_lane_flag<<endl;
                        
                        
                        r_lane_flag = 0;
                        cleaner_flag = 1;
                        
                        int j;
                        for(j = 0; j < lane_number; j++){
                            if(Gallery->Get(j) == white){
                                break;
                            }
                        }
                        if(j == lane_number){
                            
                            
                            cout<<"Clean and print, j: "<<j<<endl;
                            
                            
                            print_flag = 1;
                            while(print_flag);
                            cout<<"Player"<<PlayerColor<<" prints"<<endl;
                            round--;
                            if(round == 0){
                                exit(0);
                            }
                            sleep(1);
                            Gallery->Clear();
                            coarseLock.release_lock();
                            cleaner_flag = 0;
                        }else{
                            cleaner_flag = 0;
                            coarseLock.release_lock();
                        }
                    }
                    coarseLock.release_lock();
                }
                
            }else{
                continue;
            }
        }else{
            continue;
        }
    }
    
    #endif
    
#endif
    /**
     *  Needs synchronization. Between Red and Blue shooters.
     *  Choose a random lane and shoot.
     *  Rate: Choose a random lane every 1/rate s.
     *  PlayerColor : Red/Blue.
     */
     //Gallery->Set(0,PlayerColor);
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
#ifdef ROGUECOARSECLEANER
    while(cleaner_flag){
        for(int i = 0; i < lane_number; i++){
            if(Gallery->Get(i) == white){
                break;
            }
        }
        cleaner_flag = 0;
    }
#endif
    
    

}


void Printer(int rate)
{

    /**
     *  NOT TRANSACTION SAFE; cannot be called inside a transaction. Possible conflict with other Txs Performs I/O
     *  Print lanes periodically rate/s.
     *  If it doesn't synchronize then possible mutual inconsistency between adjacent lanes.
     *  Not a particular concern if we don't shoot two lanes at the same time.
     *
     */
    struct timeval finish;
    int time_passed;
    while(1){
        gettimeofday(&finish, 0);
        time_passed = (finish.tv_sec - start.tv_sec) * 1000000 + finish.tv_usec - start.tv_usec;
        if(time_passed % (1000000/rate) != 0){
            print_flag = 0;
            continue;
        }else{
            if(print_flag == 1){
                cout<<"Printer in working"<<endl;
                Gallery->Print();
                print_flag = 0;
            }
        }
    }
}



int main(int argc, char** argv)
{
#ifdef ROGUECOARSE
    coarseLock.lock_init();
#endif
    
    std::vector<thread> ths;
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
    //    std::thread RedShooterT,BlueShooterT,CleanerT,PrinterT;

    gettimeofday (&start, NULL);
    ths.push_back(std::thread(&ShooterAction,5,red));
    ths.push_back(std::thread(&ShooterAction,5,blue));
    ths.push_back(std::thread(&Cleaner));
    ths.push_back(std::thread(&Printer,1));

    // Join with threads
    //    RedShooterT.join();
    //  BlueShooterT.join();
    //  CleanerT.join();
    // PrinterT.join();

    for(auto& th : ths)
    {
        th.join();
    }


    return 0;
}
