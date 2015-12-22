#DIR1 = /afs/umbc.edu/users/k/h/khirsc1/home/cs341proj/proj2/src/
CXX = g++
CXXFLAGS = -std=c++0x  -ansi -Wall -g -w #  -I . -I $(DIR1)
OBJS = Driver.o HashTable.o HashLibrary.o

all: $(OBJS) 
	$(CXX) $(CXXFLAGS) $(OBJS) -o Driver.out
	
Driver.o: Driver.cpp HashTable.h HashLibrary.h
	$(CXX) $(CXXFLAGS) -c Driver.cpp	
	
HashTable.o: HashTable.h HashLibrary.h
	$(CXX) $(CXXFLAGS) -c HashTable.cpp
	
HashLibrary.o: HashLibrary.h
	$(CXX) $(CXXFLAGS) -c HashLibrary.cpp
	
clean:
	rm *.o* 
	
test:
	./Driver.out 

run:
	./Driver.out $(INPUT) $(MIN_SIZE) $(MAX_SIZE) $(MIN_BASE) $(MAX_BASE)


# INPUT=input.txt MIN_SIZE=5 MAX_SIZE=40 MIN_BASE=5 MAX_BASE=20




