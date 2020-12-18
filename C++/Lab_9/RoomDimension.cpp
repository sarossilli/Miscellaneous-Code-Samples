// 14.13
#include "RoomDimension.h"
#include "FeetInches.h"

RoomDimension::RoomDimension(int fw, int iw, int fl, int il){
    FeetInches wdth;
    wdth.setInches(iw);
    wdth.setFeet(fw);
    
    FeetInches lngth;
    lngth.setInches(il);
    lngth.setFeet(fl);

    width = wdth;
    length = lngth;
}

FeetInches RoomDimension::getArea(){
    FeetInches temp;
    temp = width * length;
    return temp;
}