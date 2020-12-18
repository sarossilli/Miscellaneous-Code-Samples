// Samuel Rossilli
// CS 3060 001
// HW3, P7.5
// Program reads in food data from the user. Reads in 5 days of data for each of the 3 monkeys, and stores the data in a 3x5 table
// It then  displays the created table, and calculates the average, least, and most ammount of food eaten by the group

// and displays the results.
#include <iostream>
using namespace std;

// contants for Table dimentions
const int DAYS =5;
const int MONKEYS = 3;

// Function Prototpyes
void getFoodEaten(double [][DAYS]);
void displayAverageDaily(double [][DAYS]);
void displayLeastEaten(double [][DAYS]);
void displayMostEaten(double [][DAYS]);

int main(){
    // Array to hold mokey data
    double food[MONKEYS][DAYS];
    
    // get amount eaten
    getFoodEaten(food);

    cout <<endl << "-------------------------FOOD STATS-------------------------" << endl;

    // Display average amount eaten daily
    displayAverageDaily(food);
    // Display the least ammount eaten 
    //displayLeastEaten(food);
    // Display the most eaten
    //displayMostEaten(food);
    return 0;
}



// Function to accept input data from the user
// Includes error checking that requires non-negitive input
void getFoodEaten(double data[][DAYS]){
    for(int i = 0; i<MONKEYS; i++){
        for(int k = 0; k<DAYS; k++){
            cout << "Input lbs. food eaten by mokey #" <<i+1 << " on day " <<k+1<< ": ";
            cin >> data[i][k];

            //INPUT CHECK
            while(data[i][k] < 0){
                cout << "Input must be positive or zero. Enter food eaten by mokey #" <<i+1 << " on day " <<k+1<< ": ";
                cin >> data[i][k];
            }
        }
        cout<<endl;
    }
    cout <<endl;
}

void displayAverageDaily(double data[][DAYS]){
    for(int day = 0; day<DAYS; day++){
        //sum is accumulator that gets reset every days
        double sum = 0.0;
        for(int monkey =0;monkey <MONKEYS; monkey++){
            //add up each monkey per day
            sum+=data[monkey][day];
        }
        double avg = sum/MONKEYS;
        cout << "Average on day " << day+1 << ": " << avg <<endl;
    }
    cout<<endl;
}



// Function that finds the lowest value in the table
void displayLeastEaten(double data[][DAYS]){
    //smallest is the least value found in the table
    double smallest = data[0][0];
    double monkeySmallest = data[0][0];
    for(int i = 0; i<MONKEYS; i++){
        for(int k = 0; k<DAYS; k++){
            //if a smaller value is found, this is the new smallest
            if (smallest > data[i][k]){
                smallest = data[i][k];
            }
        }
    }
}

// Function that finds the highest value in the table
void displayMostEaten(double data[][DAYS]){
    double most = data[0][0];
    for(int i = 0; i<MONKEYS; i++){
        for(int k = 0; k<DAYS; k++){
            //if a larger value is found, it becoms the new 'most'
            if (most < data[i][k]){
                most = data[i][k];
            }
        }
    }
}
