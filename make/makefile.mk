testdate : Date.o testDate.o
	g++ -o testdate Date.o testdate.o

testdate.o : testDate.cpp Date.h
	g++ -c testDate.cpp

Date.o : Date.cpp Date.h
	g++ -c Date.cpp