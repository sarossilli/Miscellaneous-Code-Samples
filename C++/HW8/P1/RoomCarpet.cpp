#include "RoomCarpet.h"
#include "RoomDimension.h"

RoomCarpet::RoomCarpet(int fw, int iw, int fl, int il, double price){
    RoomDimension dim(fw,iw,fl,il);
    dimension = dim;
    pricePerSqFt = price;
    totalCost = calculateTotal();
}

double RoomCarpet::calculateTotal(){
    double ans;
    FeetInches dim = dimension.getArea();

    // Price per sq ft * sq ft
    ans = (dim.getFeet() + (dim.getInches())/12.0)* pricePerSqFt;
    return ans;
}

double RoomCarpet::getTotal(){
    return totalCost;
}