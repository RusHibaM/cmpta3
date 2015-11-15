
all: Shooter

Shooter: Shooter.o 
	g++ -mrtm -std=c++11 -pthread $< -o $@

Shooter.o: Shooter.cpp
	g++ -c -mrtm -std=c++11 -pthread $<

Shooter_Coarse:
        g++ -DROGUECOARSE2 -DCHECKFIRST -mrtm -std=c++11 -pthread -o Shooter Shooter.cpp

clean:
	rm -rf *o Shooter