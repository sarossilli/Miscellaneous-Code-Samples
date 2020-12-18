#include <iostream>
using namespace std;

double kenetic(double, double);

int main(){
    double mass;
    double vel;

    do{    
        cout<<"Mass: ";
        cin >> mass;
    }while(mass<0);

    do{
        cout<<"Velocity: ";
        cin >> vel;
    }while(vel < 0 );

    double k = kenetic(mass,vel);
    cout << k << " J" << endl;
    return 0;
}

double kenetic(double mass, double vel){double k = (0.5 * mass * (vel*vel)); return k; }