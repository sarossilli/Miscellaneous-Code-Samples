#include "RoomCarpet.h"
#include <iostream>

using namespace std;

int main(){
    // Vars to hold user input
    int length_ft;
    int length_in;
    int width_ft;
    int width_in;
    double price;


    cout << "Enter number of feet of the room length: ";
    cin >> length_ft;
    cout << endl;
    while(length_ft<0){
        cout << "Enter number of feet of the room length: ";
        cin >> length_ft;
        cout << endl;
    }

    cout << "Enter number of inches of the room length: ";
    cin >> length_in;
    cout << endl;
    while(length_in<0){
        cout << "Enter number of inches of the room length: ";
        cin >> length_in;
        cout << endl;
    }

    cout << "Enter number of feet of the room width: ";
    cin >> width_ft;
    cout << endl;
    while(width_ft<0){
        cout << "Enter number of feet of the room width: ";
        cin >> width_ft;
        cout << endl;
    }

    cout << "Enter number of inches of the room width: ";
    cin >> width_in;
    cout << endl;
    while(width_in<0){
        cout << "Enter number of inches of the room width: ";
        cin >> width_in;
        cout << endl;
    }

    cout << "Enter price per square foot: ";
    cin >> price;
    cout << endl;
    while(price<0){
        cout << "Enter price per square foot: ";
        cin >> price;
        cout << endl;
    }


    //Create RoomCarpet object with user input
    RoomCarpet carpet(length_ft,length_in,width_ft,width_in,price);

    //Output total price
    cout <<endl<< "Total Price: $" << carpet.getTotal() << endl;

    return 0;
}