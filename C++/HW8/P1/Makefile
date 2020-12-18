all: program

program: main.o RoomCarpet.o RoomDimension.o FeetInches.o 
	g++ main.o RoomCarpet.o RoomDimension.o FeetInches.o -o program

main.o: main.cpp
	g++ -c main.cpp

RoomCarpet.o: RoomCarpet.cpp
	g++ -c RoomCarpet.cpp 

RoomDimension.o: RoomDimension.cpp
	g++ -c RoomDimension.cpp 

FeetInches.o: FeetInches.cpp
	g++ -c FeetInches.cpp 

clean:
	rm *.o