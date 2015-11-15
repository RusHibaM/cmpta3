
all: Shooter

Shooter: Shooter.o 
	g++ -mrtm -std=c++11 -pthread $< -o $@

Shooter.o: Shooter.cpp
	g++ -c -mrtm -std=c++11 -pthread $<

Shooter_Coarse:
	g++ -DROGUECOARSE -DLOCKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp

Shooter_Coarse2:
	g++ -DROGUECOARSE2 -DLOCKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp

Shooter_Fine:
	g++ -DROGUEFINE -DLOCKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp

Shooter_Fine2:
	g++ -DROGUEFINE2 -DLOCKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp

Shooter_Coarse_Cleaner:
	g++ -DROGUECOARSE -DROGUECOARSECLEANER -DLOCKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp

Shooter_Coarse2_Cleaner:
	g++ -DROGUEFINE -DROGUECOARSECLEANER -DLOCKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp

Shooter_Fine_Cleaner:
	g++ -DROGUECOARSE2 -DROGUEFINECLEANER -DLOCKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp

Shooter_Fine2_Cleaner:
	g++ -DROGUEFINE2 -DROGUEFINECLEANER -DLOCKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp


Shooter_Coarse_Checkfirst:
	g++ -DROGUECOARSE -DCHECKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp

Shooter_Coarse2_Checkfirst:
	g++ -DROGUEFINE -DCHECKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp

Shooter_Fine_Checkfirst:
	g++ -DROGUECOARSE2 -DCHECKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp

Shooter_Fine2_Checkfirst:
	g++ -DROGUEFINE2 -DCHECKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp

Shooter_Coarse_Cleaner_Checkfirst:
	g++ -DROGUECOARSE -DROGUECOARSECLEANER -DCHECKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp

Shooter_Coarse2_Cleaner_Checkfirst:
	g++ -DROGUEFINE -DROGUECOARSECLEANER -DCHECKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp

Shooter_Fine_Cleaner_Checkfirst:
	g++ -DROGUECOARSE2 -DROGUEFINECLEANER -DCHECKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp

Shooter_Fine2_Cleaner_Checkfirst:
	g++ -DROGUEFINE2 -DROGUEFINECLEANER -DCHECKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp


clean:
	rm -rf *o Shooter