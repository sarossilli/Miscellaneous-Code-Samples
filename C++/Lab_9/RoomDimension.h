#pragma once

#ifndef ROOMDIMENSION_H
#define ROOMDIMENSION_H

#include "FeetInches.h"

class RoomDimension
{
private:
    FeetInches width;
    FeetInches length;
    double area;

public:

    // default constructor
    RoomDimension(){
        width = FeetInches();
        length = FeetInches();
        area = 0.0;
    }

    // Copy constructor:

    //getArea Function
    double getArea(){
        return area;
    }
};

#endif