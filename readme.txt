This is a description of my codes for CMPT-431 assignment 3.

For the the rogues and cleaners in which the transactions are not used, please test codes in this folder. If you find there is something wrong with the commands below, please check in the Makefile file. Thank you.

/* Compile Usage */
use:
	make Shooter_Coarse
to get:
	Rogues with coarse lock and each rogue shoot one lane at a time.
	The rogues themselves will clean the lanes
	Get lock first, then go check the lane

use:
	make Shooter_Coarse2
to get:
	Rogues with coarse lock and each rogue shoot two lanes at a time
	The rogues themselves will clean the lanes
	Get lock first, then go check the lane

use:
	make Shooter_Fine
to get:
	Rogues with fine locks and each rogue shoot two lane at a time
	The rogues themselves will clean the lanes
	Get lock first, then go check the lane

use:
	make Shooter_Fine2
to get:
	Rogues with fine locks and each rogue shoot two lanes at a time
	The rogues themselves will clean the lanes
	Get lock first, then go check the lane

use:
	make Shooter_Coarse_Cleaner
to get:
	Rogues with coarse lock and each rogue shoot one lane at a time
	A cleaner with coarse lock will do the clean only
	Get lock first, then go check the lane

use:
	make Shooter_Coarse2_Cleaner
to get:
	Rogues with coarse lock and each rogue shoot two lanes at a time
	A cleaner with coarse lock will do the clean only
	Get lock first, then go check the lane

use:
	make Shooter_Fine_Cleaner
to get:
	Rogues with fine locks and each rogue shoot two lane at a time
	A cleaner with fine lock will do the clean only
	Get lock first, then go check the lane

use:
	make Shooter_Fine2_Cleaner
to get:
	Rogues with fine locks and each rogue shoot two lanes at a time
	A cleaner with fine lock will do the clean only
	Get lock first, then go check the lane


use:
	make Shooter_Coarse_Checkfirst
to get:
	Rogues with coarse lock and each rogue shoot one lane at a time.
	The rogues themselves will clean the lanes
	Check the lane first, then get the lock

use:
	make Shooter_Coarse2_Checkfirst
to get:
	Rogues with coarse lock and each rogue shoot two lanes at a time
	The rogues themselves will clean the lanes
	Check the lane first, then get the lock

use:
	make Shooter_Fine_Checkfirst
to get:
	Rogues with fine locks and each rogue shoot two lane at a time
	The rogues themselves will clean the lanes
	Check the lane first, then get the lock

use:
	make Shooter_Fine2_Checkfirst
to get:
	Rogues with fine locks and each rogue shoot two lanes at a time
	The rogues themselves will clean the lanes
	Check the lane first, then get the lock

use:
	make Shooter_Coarse_Cleaner_Checkfirst
to get:
	Rogues with coarse lock and each rogue shoot one lane at a time
	A cleaner with coarse lock will do the clean only
	Check the lane first, then get the lock

use:
	make Shooter_Coarse2_Cleaner_Checkfirst
to get:
	Rogues with coarse lock and each rogue shoot two lanes at a time
	A cleaner with coarse lock will do the clean only
	Check the lane first, then get the lock

use:
	make Shooter_Fine_Cleaner_Checkfirst
to get:
	Rogues with fine locks and each rogue shoot two lane at a time
	A cleaner with fine lock will do the clean only
	Check the lane first, then get the lock

use:
	make Shooter_Fine2_Cleaner_Checkfirst
to get:
	Rogues with fine locks and each rogue shoot two lanes at a time
	A cleaner with fine lock will do the clean only
	Check the lane first, then get the lock


For those in which RTM is used, please go to the tsx_tools.

First cd tsx_tools . And there will be a Makefile file.

use:
	make Shooter_TM
to get:
	Rogues with RTM transaction implemented and each rogue shoot one lane at a time.
	The rogues themselves will clean the lanes

use:
	make Shooter_TM2
to get:
	Rogues with RTM transaction implemented and each rogue shoot two lanes at a time
	The rogues themselves will clean the lanes

use:
	make Shooter_TM_Cleaner
to get:
	Rogues with RTM transaction implemented and each rogue shoot one lane at a time.
	A cleaner will do the clean only

use:
	make Shooter_TM2_Cleaner
to get:
	Rogues with RTM transaction implemented and each rogue shoot two lanes at a time
	A cleaner will do the clean only


/* Run the program */
use:
	./Shooter -r [red shoot rate] -b [blue shoot rate] -n [round] -l [lane number]
All the four parameters are required
 

/* Output */

/** First the basic information **/
Red rate set to: 5
Blue rate set to: 5
Round set to: 3
Number of lanes set to: 6

/** Then there will be measured data **/
Red shoot rate: 2.22227
Blue shoot rate: 1.11113
Time used to wait for lock: 0
Total time used: 1799963
/** For version with transaction there will be abort rate for the RTM I used **/

/** Then output all the lanes **/



