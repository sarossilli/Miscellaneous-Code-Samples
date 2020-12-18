// Sam Rossilli P 14.13
// FeetInches class
// Adapted From Book Implementation

#include <cstdlib>
#include "FeetInches.h"

void FeetInches::simplify(){
    if (inches >= 12){
        feet += (inches/12);
        inches = inches%12;
    }
    else if (inches < 0){
        feet -= ((abs(inches) / 12 ) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}

// Multiplication operator
FeetInches FeetInches::operator * (const FeetInches &right){
    FeetInches temp;

    //Convert all to inches and multiply them
    temp.inches = ((feet*12)+inches) * ((right.feet*12) + right.inches);

    // Convert square inches into square feet/sq inches
    if(temp.inches>=144){
        //144 sq inch per sq ft
        temp.feet += temp.inches/144;
        temp.inches = (temp.inches%144)/12;
    }

    return temp;
}