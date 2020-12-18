// Sam Rossilli P 14.13
// RoomCarpet class
#pragma once

#ifndef ROOMCARPET_H
#define ROOMCARPET_H

// include headers
#include "RoomDimension.h"

class RoomCarpet
{
private:
    RoomDimension dimension;
    double pricePerSqFt;

public:
    RoomCarpet(RoomDimension rd, double c){
        dimension = rd;
        pricePerSqFt = c;
    }

    double getTotalCost(){
        double area = dimension.getArea();
        return area*pricePerSqFt;
    }

};

#endif