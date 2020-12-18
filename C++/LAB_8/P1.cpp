// 12.11
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SIZE = 12;

struct Division{
    string name[SIZE];
    int quarter;
    double sales;
};

int main(){
    // Need file stream obj
    fstream file("corp.dat", ios::out|ios::binary);
    //structts for each division
    Division east,west,north,south;
    //Counter
    int qtr;
    //assign names to the structs
    strcpy_s(east.name, "East");
    strcpy_s(west.name, "West");
    strcpy_s(north.name, "North");
    strcpy_s(south.name, "South");


    cout << "enter sales East"<<endl;
    for(qtr=1; qtr<5; qtr++){
        east.quarter = qtr;
        cout << "\t Quarter" << qtr<< ": ";
        cin >> east.sales;
        file.write(reinterpret_cast<char *>(&east), sizeof(east));
    }

     cout << "enter sales West"<<endl;
    for(qtr=1; qtr<5; qtr++){
        east.quarter = qtr;
        cout << "\t Quarter" << qtr<< ": ";
        cin >> east.sales;
        file.write(reinterpret_cast<char *>(&east), sizeof(east));
    }

        cout << "enter sales North"<<endl;
    for(qtr=1; qtr<5; qtr++){
        north.quarter = qtr;
        cout << "\t Quarter" << qtr<< ": ";
        cin >> north.sales;
        file.write(reinterpret_cast<char *>(&north), sizeof(north));
    }
        cout << "enter sales South"<<endl;
    for(qtr=1; qtr<5; qtr++){
        east.quarter = qtr;
        cout << "\t Quarter" << qtr<< ": ";
        cin >> east.sales
        file.write(reinterpret_cast<char *>(&south), sizeof(east));
    }
    return 0;
}