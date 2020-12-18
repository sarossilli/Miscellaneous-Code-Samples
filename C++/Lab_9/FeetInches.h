// Sam Rossilli P 14.13
// FeetInches class
// Adapted From Book Implementation

#ifndef FEETINCHES_H
#define FEETINCHES_H

#include <iostream>
using namespace std;
class FeetInches
{
private:
    int feet;
    int inches;
    void simplify();

public:
    FeetInches(int f,int i){
        feet=f;
        inches = i;
        simplify();
    }
    
    //Copy Constructor
    FeetInches(FeetInches& right){
        feet = right.feet;
        inches = right.inches;
    }

    //mutator
    void setFeet(int f){ feet = f; }
    void setInches(int i){
        inches = i;
        simplify();
    }

    //accessors
    int getFeet(){return feet;}    
    int getInches(){return inches;}    


};

#endif