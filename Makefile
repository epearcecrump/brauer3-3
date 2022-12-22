exec: main.o convert.o
	g++ main.o convert.o -o exec 

main.o: main.cpp brauer.h
	g++ -Wall -g -c -std=c++11 main.cpp

convert.o: convert.cpp brauer.h
	g++ -Wall -g -c -std=c++11 convert.cpp

clean:
	rm -rf *.o exec
