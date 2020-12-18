// Samuel Rossilli
// CS 3060 001
// HW2, P6.18
// Program reads in number of rooms to paint, cost of paint per gallon, and the area per room to paint
// It then calculates the gallons of paint, the hours of labour, and the paint and labour costs 
// and displays the results to a formatted table.

#include <iostream>
#include <iomanip> 
using namespace std;

// Constant for labour cost as specified in the problem statement
int PAY_PER_HOUR = 25;

// Constants for output formatting
int SET_W = 25;
int SET_W_DOUBLES = 8;

// Function Prototypes
void getInputs(int &,double &,double &);
double calculatePaint(double);
double calculateHours(double);
double calculatePaintCost(double,double);
double calculateLabourCost(double);
void display(double,double,double,double);

int main(){
    // Variables to read from user
    int rooms;
    double paintCostPerGallon, areaPerRoom;
    // Varaibles to calculate
    double labourCost, paintCostTotal, hours,gallons;
    
    //Read in user input
    getInputs(rooms,paintCostPerGallon,areaPerRoom);
    
    //Complete Calculations
    gallons = calculatePaint(rooms*areaPerRoom);
    hours = calculateHours(rooms*areaPerRoom);
    paintCostTotal = calculatePaintCost(paintCostPerGallon,gallons);
    labourCost = calculateLabourCost(hours);

    //Display results
    display(gallons,hours,paintCostTotal,labourCost);

    return 0;
}

// *************************************************
// Functions to calculate gallons, hours, and costs
// totalArea holds the total area to be painted (rooms * area per room)
// Returns double
// *************************************************
double calculatePaint(double totalArea){
    return (totalArea)/110; // 1 gallon per 110 area as specified in the problem statement
}
double calculateHours(double totalArea){
    return (8* totalArea)/110; // 8 hours per 110 area as specified in te problem statement
}
double calculatePaintCost(double paintCostPerGallon, double gallons){
    return paintCostPerGallon * gallons;
}
double calculateLabourCost(double hours){
    return hours*PAY_PER_HOUR;
}

// **************************************************************************************
// Function that gets the user input for number of rooms, paint cost, and area per room
// Uses reference variables to get all three variables from the user
// Includes error checking for each input based on requirements from the problem statement
// **************************************************************************************
void getInputs(int &rooms, double &paintCost, double &areaPerRoom){
    do{
        cout << "Input number of rooms that need paint: ";
        cin >> rooms;
    } while(rooms<1);

    do{
        cout << "Input the cost of paint per gallon: $";
        cin >> paintCost;
    } while(paintCost<=10.0);

    do{
        cout << "Input area per room that needs to be painted: ";
        cin >> areaPerRoom;
    } while(areaPerRoom<1);
}

// ***************************************************************************
// Function to display a formatted table of gallons neede, hours, and costs
// Uses constants SET_W and SET_W_DOUBLES to format the table spacing
// ***************************************************************************
void display(double gallons, double hours, double paintCost, double labourCost){
    // Set decimal format
    cout <<left<< setprecision(2) << fixed << showpoint;

    cout << "\nPaint Job Estimate\n-------------------------------------------" << endl;
    cout << left << setw(SET_W) << "Gallons of Paint Needed: " << right << setw(SET_W_DOUBLES+1) << gallons << endl;
    cout << left << setw(SET_W) << "Hours of Labour Needed: " << right << setw(SET_W_DOUBLES+1) << hours << endl;
    cout << left << setw(SET_W) << "Total Cost of Paint:" << "$"<< setw(SET_W_DOUBLES) << right  << paintCost << endl;
    cout << left << setw(SET_W) << "Total Cost of Labour:" << "$"<< setw(SET_W_DOUBLES) << right << labourCost << endl;
    cout << left << setw(SET_W) << "Total Estimate:" << "$"<< setw(SET_W_DOUBLES) << right << paintCost+labourCost << endl;
}