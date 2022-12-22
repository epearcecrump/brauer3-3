exec: main.o
	g++ main.o -o exec 

main.o: main.cpp brauer.h
	g++ -Wall -g -c -std=c++11 main.cpp

clean:
	rm -rf *.o exec
