#ifndef ROOMDIMENSION_H
#define ROOMDIMENSION_H

#include "FeetInches.h"

class RoomDimension
{
private:
    FeetInches width;
    FeetInches length;

public:
    RoomDimension(int,int,int,int);
    RoomDimension(){
        width = FeetInches();
        length = FeetInches();
    }
    FeetInches getArea();
};

#endif