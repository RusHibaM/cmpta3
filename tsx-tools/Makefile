
all: Shooter

Shooter: Shooter.o 
	g++ -mrtm -std=c++11 -pthread $< -o $@

Shooter.o: Shooter.cpp
	g++ -c -mrtm -std=c++11 -pthread $<

Shooter_Coarse:
	g++ -DROGUETM -mrtm -std=c++11 -pthread -o Shooter rtm.cpp

Shooter_Coarse2:
	g++ -DROGUETM2 -mrtm -std=c++11 -pthread -o Shooter rtm.cpp

Shooter_Coarse_Cleaner:
	g++ -DROGUETM -DROGUECLEANER -mrtm -std=c++11 -pthread -o Shooter rtm.cpp

Shooter_Coarse2_Cleaner:
	g++ -DROGUETM2 -DROGUECLEANER -mrtm -std=c++11 -pthread -o Shooter rtm.cpp



clean:
	rm -rf *o Shooter