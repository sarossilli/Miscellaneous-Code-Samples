// Samuel Rossilli
// CS 3060 001
// HW4, P9.8
// Program finds the mean of the array. Uses pointer arithmetic to access array elements
// Also,if there is no mean, returns -1 

#include <iostream>
using namespace std;

int mode(int*,int);

int main(){
    //List used for testing
    const int SIZE = 30;
    int list[] = {1,3,4,3,4,6,4,8,4,8,6,1,8,4,8,6,1,8,4,7,8,6,1,2,3,8,4,5,6,1};

    //Find and print the mean
    int meanVal = mode(list,SIZE);
    return 0;
}

int mode(int* lst,int size){
    int m = -1; //Holds the highest number of occurences
    int mval = -1; //Holds the value of the mean
    //Traverse through each value in array
    for(int i = 0;i<size;i++){
        int count = 0; //temporary count variable to count number of occurences for each number
        int val = *(lst+i);

        //compare each value the others to count number of observations
        for(int k = 0; k<size; k++){
            if(*(lst+k) == val){
                count++;
            }

            //if this is a new highest-number of observations, 
            // then this could be the mean vlaue
            if ( count>1 && m<count) {
                m = count;
                mval = val;
            }
        }
    }
    cout << "The mean is: " << mval << " with " << m << " occurences" << endl;
    return mval;
}

