// 13.3
// Samuel Rossilli
// HW7: 13.3
// Basic 'car' class
// Prompts and initializes a car object
// Then calls the accelerate funcion 5 times and prints the speed after each call
// And calls the breakSpeed function 5 times and prints the speed after each call
#include <iostream>
using namespace std;

class Car{
    // Private member variables
    private:
        int yearModel;
        string make;
        int speed;

    public:
    //Constructor if speed is not specified. Sets speed to 0
    Car(int year, string mk){
        yearModel = year;
        make = mk;
        speed = 0;
    }

    // increases speed by 5
    void accelerate(){
        speed+=5;
    }

    // Decreases speed by 5
    void breakSpeed(){
        speed-=5;
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
};

int main(){
    int year = 2020;
    string name = "Porsche";

    Car porsche(year,name);

    //Show initilized speed is zero
    cout << "Accelerating and braking " << porsche.getYear() << " " << porsche.getModel() << endl << "----------------------------------" << endl;
    cout << "Initialized Speed: " << porsche.getSpeed() << endl;

    //Accelerate 5 times
    for( int i = 0; i<5; i++){
        porsche.accelerate();
        cout << "Accelerated Speed: " << porsche.getSpeed() << endl;
    }   

    //Brake 5 times
    cout << "----------------------------------" << endl <<  "Starting brake " << porsche.getYear() << " " << porsche.getModel() << endl << "----------------------------------" << endl;
    for( int i = 0; i<5; i++){
        porsche.breakSpeed();
        cout << "Brake Speed: " << porsche.getSpeed() << endl;
    }     
    
    return 0;
}

