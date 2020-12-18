#include <iostream>

#include "FeetInches.h"
#include "RoomCarpet.h"
#include "RoomDimension.h"

int main(){
    int lengthFeet, lengthInches;
    int widthFeet, widthInches;

    cout << "enter room length:\n\tFeet: ";
    cin >> lengthFeet;
    cout <<"\tInches:";
    cin >> lengthInches;

    cout << "enter room width:\n\tFeet: ";
    cin >> widthFeet;
    cout <<"\tInches:";
    cin >> widthInches;

    FeetInches length = FeetInches(lengthFeet,lengthInches);


    return 0;
}