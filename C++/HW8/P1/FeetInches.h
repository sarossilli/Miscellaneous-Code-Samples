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
    FeetInches(int f = 0,int i = 0){
        feet=f;
        inches = i;
        simplify();
    }

    void setFeet(int f){
        feet = f;
    }

    void setInches(int i){
        inches = i;
    }

    int getFeet(){return feet;}    
    int getInches(){return inches;}    

    // creating the multiplication operation
    FeetInches operator * (const FeetInches &);


};

#endif