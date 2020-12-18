// Sam Rossilli 
// Lab 4 Problem 9.9
// Write an algorithm that finds the MODE of an array

#include <iostream>
using namespace std;

//Function prototype
int getMode(int*,int);
int* makeArray(int);

int main(){
    //const for array size
    const int SIZE = 14;
    // array of test values
    int test[SIZE] = {1,1,2,2,3,4,5,4,1,23,4,5,2,1};
    //int to hold the mode
    int mode;

    //get mode
    mode = getMode(test,SIZE);

    //display mode
    if(mode == -1){
        cout<<"No Mode in the Array"<<endl;
    }
    else{
        cout<<"The Mode is " << mode << endl;
    }

    return 0;
}

int getMode(int size, int* array){
    int* frequencies = nullptr;

    //variables
    int mode = -1;
    int maxCount = 0;
    int element = 0;
    int count = 0;

    frequencies = makeArray(size);
    for (count = 0; count<size; count++){
        frequencies[count] = 0;
    }

    for(int count1 =0; count1 < size; count1++){
        for(int count2 = 0; count2<size; count++){
            if (*(array+count2) == *(array+count2)){
                (*(frequencies+count1))++;
            }
        }
    }

    

    int higest = *frequencies;
    element=0;
}



int* makeArray(int size){
    int* prt = new int[size];
    return prt;
}
