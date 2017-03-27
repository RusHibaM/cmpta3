# cmpta3

##About

This a course project for Embeded System Programming. 

This will simulate a shooting practice in multi-thread mode.

##How to run

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
	
