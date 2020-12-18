// Samuel Rossilli
// HW7: 13.3
// Basic 'car' class
// Prompts and initializes a car object
// Then calls the accelerate funcion 5 times and prints the speed after each call
// And calls the breakSpeed function 5 times and prints the speed after each call
#include <iostream>
using namespace std;

class Car{
    public:
    // Constructors

    // Constructor for if speed is specified
    Car(int year, string mk,int spd){
        yearModel = year;
        make = mk;
        speed = spd;
    }

    //Constructor if speed is not specified. Sets speed to 0
    Car(int year, string mk){
        yearModel = year;
        make = mk;
        speed = 0;
    }

    // Accessors
    int getSpeed(){
        return speed;
    }
    string getModel(){
        return make;
    }
    int getYear(){
        return yearModel;
    }

    // Setters
    void setSpeed(int spd){
        speed = spd;
    }
    void setYear(int yr){
        yearModel = yr;
    }
    void setMake(string mk){
        make = mk;
    }

    // increases speed by 5
    void accelerate(){
        speed+=5;
    }

    // Decreases speed by 5
    void breakSpeed(){
        speed-=5;
    }

    // Private member variables
    private:
        int yearModel;
        string make;
        int speed;
};

int main(){
    int year;
    char input[20];
    // Prompt user for car info:
    cout << "Enter Car Year: ";
    cin >> year;
    
    cin.ignore(1, '\n'); 

    cout << endl << "Enter car make: ";
    cin.getline(input,20);
    //initialize car object
    Car car(year,input);

    //Show initilized speed is zero
    cout << "Accelerating and braking " << car.getYear() << " " << car.getModel() << endl << "----------------------------------" << endl;
    cout << "Initialized Speed: " << car.getSpeed() << endl;

    //Accelerate 5 times
    for( int i = 0; i<5; i++){
        car.accelerate();
        cout << "Accelerated Speed: " << car.getSpeed() << endl;
    }   

    //Brake 5 times
    cout << "----------------------------------" << endl <<  "Starting brake " << car.getYear() << " " << car.getModel() << endl << "----------------------------------" << endl;
    for( int i = 0; i<5; i++){
        car.breakSpeed();
        cout << "Brake Speed: " << car.getSpeed() << endl;
    }     
    
    return 0;
}

