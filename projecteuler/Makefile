
CPP		=	g++
LD		=	g++
#AR		=	ar
#RANLIB	=	ranlib
#OBJCOPY	=	objcopy

%.o: %.cpp
	$(CPP) -std=c++11 -O3 -c $< -o $@

primes: primes.o
	$(LD) -o $@ $<    

.PHONY: clean

clean:
	rm -rf primes.o primes

