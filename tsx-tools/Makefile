
all: Shooter

Shooter: Shooter.o 
	g++ -mrtm -std=c++11 -pthread $< -o $@

Shooter.o: Shooter.cpp
	g++ -c -mrtm -std=c++11 -pthread $<

Shooter_TM:
	g++ -DROGUETM -mrtm -std=c++11 -pthread -o Shooter rtm.cpp

Shooter_TM2:
	g++ -DROGUETM2 -mrtm -std=c++11 -pthread -o Shooter rtm.cpp

Shooter_TM_Cleaner:
	g++ -DROGUETM -DROGUECLEANER -mrtm -std=c++11 -pthread -o Shooter rtm.cpp

Shooter_TM2_Cleaner:
	g++ -DROGUETM2 -DROGUECLEANER -mrtm -std=c++11 -pthread -o Shooter rtm.cpp



clean:
	rm -rf *o Shooter