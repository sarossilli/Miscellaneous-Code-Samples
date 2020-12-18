// Samuel Rossilli
// Lab 4: Problem 8.8
// Implement a binary search and linear search algorithm

#include <iostream>
using namespace std;

//global Constants
const int ARRAY_SIZE = 20;

// Function Prototype
int linearSearchBench(int[],int,int);
int binarySearchBench(int[],int,int);

int main(){
    int comparisons; // to hold number of comparisons
    
    // Initialize array with 20 integer values
    int test[ARRAY_SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    
    // Display the value being searched for
    cout << "Searching the arary for 18, near the end of the array" << endl;

    // Perform the linear search
    comparisons = linearSearchBench(test,ARRAY_SIZE,18);

    //Display results of Linear Search
    cout << "The linear search found the value after " << comparisons << " number of comparisons." << endl;

    // Perform the binary search
    comparisons = binarySearchBench(test,ARRAY_SIZE,18);

    // Display results of the Binary Search
    cout << "The binary search found the value after " << comparisons << " number of comparisons." << endl;

    return 0;
}

int linearSearchBench(int array[],int size, int search){
    //Variables
    int comparison = 0;
    bool found = false;
    int index = 0;

    //Itterate while value is not found
    // and index is within array bounds
    while (!found && (index < size)) {
        comparison++;
        if(array[index] == search){
            found=true;
        }
        index++;
    }
    // Return comparrisons
    return comparison;
}

int binarySearchBench(int array[],int size, int search){
    int comparison = 0;
    bool found = false;
    
    int first = 0;
    int mid;
    int last = size;


    while (!found && first<last){
        mid = (first+last)/2;
        comparison++;

        if(array[mid] == search){
            found = true;
        }
        else if(array[mid] > search){

        }
    }
}