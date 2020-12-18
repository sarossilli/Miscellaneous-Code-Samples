// Sam Rossilli P 14.13
// RoomCarpet class

#ifndef ROOMCARPET_H
#define ROOMCARPET_H
#include "RoomDimension.h"

class RoomCarpet
{
private:
    RoomDimension dimension;
    double pricePerSqFt;
    double totalCost;
public:
    RoomCarpet(int,int,int,int,double);
    RoomCarpet(){
        RoomDimension dimension(0,0,0,0);
        pricePerSqFt = 0;
    }
    double calculateTotal();
    double getTotal();
    void setPrice(double);
};

#endif