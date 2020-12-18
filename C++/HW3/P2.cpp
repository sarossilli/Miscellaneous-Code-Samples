// Samuel Rossilli
// CS 3060 001
// HW3, P7.5
// Program reads in food data from the user. Reads in 5 days of data for each of the 3 monkeys, and stores the data in a 3x5 table
// It then  displays the created table, and calculates the average, least, and most ammount of food eaten by the group

// and displays the results.
#include <iostream>
using namespace std;

// contants for Table dimentions
const int COLS =5;
const int ROWS = 3;

// Function Prototpyes
void inputData(double [][COLS]);
void printData(double [][COLS]);
double getAvg(double [][COLS]);
double getMin(double [][COLS]);
double getMax(double [][COLS]);

int main(){
    // Input data into table 
    double data[ROWS][COLS];
    inputData(data);

    // Display table
    cout << endl << "-------------------------FOOD TABLE-------------------------" << endl;
    printData(data);

    // Display table stats
    cout <<endl << "-------------------------FOOD STATS-------------------------" << endl;
    cout << "The Average lbs. of Food Eaten: " << getAvg(data) << endl;
    cout << "The Least lbs. of Food Eaten: " << getMin(data) << endl;
    cout << "The Most lbs. of Food Eaten: " << getMax(data) << endl;
    return 0;
}

// Function to accept input data from the user
// Includes error checking that requires non-negitive input
void inputData(double data[][COLS]){
    for(int i = 0; i<ROWS; i++){
        for(int k = 0; k<COLS; k++){
            do{
                cout << "Input lbs. food eaten by mokey #" <<i+1 << " on day " <<k+1<< ": ";
                cin >> data[i][k];
            }while(data[i][k] < 0);
        }
        cout<<endl;
    }
    cout <<endl<<endl;
}

// Function that prints table of input data
void printData(double data[][COLS]){
    cout << "Monkey # \tDay:1\tDay:2\tDay:3\tDay:4\tDay:5"<<endl;
      for(int i = 0; i<ROWS; i++){
        cout << "Monkey " << i+1 << "\t";
        for(int k = 0; k<COLS; k++){
            cout << data[i][k] << "\t";
        }
        cout << endl;
    }
}

// Function that finds the average of the table
double getAvg(double data[][COLS]){
    // Sum holds cumulative sum of all values in the table
    double sum = 0;
    for(int i = 0; i<ROWS; i++){
        for(int k = 0; k<COLS; k++){
            sum+=data[i][k];
        }
    }
    //avg = sum/#ofElements
    return (sum/(COLS*ROWS));
}

// Function that finds the lowest value in the table
double getMin(double data[][COLS]){
    //smallest is the least value found in the table
    double smallest = data[0][0];
    for(int i = 0; i<ROWS; i++){
        for(int k = 0; k<COLS; k++){
            //if a smaller value is found, this is the new smallest
            if (smallest > data[i][k]){
                smallest = data[i][k];
            }
        }
    }
    return (smallest);
}

// Function that finds the highest value in the table
double getMax(double data[][COLS]){
    //most is the largest value found in the table
    double most = data[0][0];
    for(int i = 0; i<ROWS; i++){
        for(int k = 0; k<COLS; k++){
            //if a larger value is found, it becoms the new 'most'
            if (most < data[i][k]){
                most = data[i][k];
            }
        }
    }
    return (most);
}
