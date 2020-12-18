// Sam Rossilli 
// Lab 4 Problem 9.9
// Write an algorithm that finds the mdian of an array

#include <iostream>
using namespace std;

double median(int*, int);
void displayArray(int*, int);

int main(){

    int odd[] = {1,3,5};
    int even[] = {2,4,6,8};

    displayArray(odd,3);

    cout<<"median of odd is : " << median(odd,4) << endl;

    displayArray(even,4);

    cout<<"median of even is : " << median(even,4)<< endl;

}

double median(int* arr, int size){
    double med;
    int* tmp;

    if(size%2){
        med = (*(arr + (size/2)) + *(arr + (size/2) + 1))/2.0;
    }
    else{
        med = *(arr + (size/2));
    }
    return med;
}

void displayArray(int* arr , int size){
    cout<<endl;
    for(int k = 0; k<size; k++){
        cout << arr[k] << "\t";
    }
    cout<<endl;
}