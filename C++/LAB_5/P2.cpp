// Samuel Rossilli
// CS 3060 001
// HW4, P9.8
// Program finds the mean of the array. Uses pointer arithmetic to access array elements
// Also,if there is no mean, returns -1 

#include <iostream>

using namespace std;

struct Customer{
    string name;
    string adress;
    string city, state, zip;
    int phone;
    double balance;
    string lastPay;

};

void getInfo(Customer&);
void showInfo(Customer);
void showSearch(Customer[],string,int);


int main(){
    static int NUM_ACCOUNTS;
    Customer account[NUM_ACCOUNTS];
    int maxCust=0;
    int choice;
    int cust;
    int count;
    string search;
    
    do{
        cout<<"Enter 1 to enter account information"<<endl;
        cout<<"Enter 2 to change an existing account" << endl;
        cout<<"Enter 3 to display all account info" << endl;
        cout<<"Enter 4 to search for a cutomer"<< endl;
        cout<<"Enter 5 to exit"<< endl;
        cin>>choice;
        
        while(choice<1 || choice>5){
            cout<<"Invalid choice: " <<endl;
            cin>>choice;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter Info: " << endl;
            cin.get();
            getInfo(account[maxCust]);
            cout << "You have entered info for cutomer number " << maxCust<<endl;
            maxCust++;
            break;
        case 2:
            cout << "Customer Number: ";
            cin >> cust;
            while(cust<0||cust>= maxCust){
                cout << "Error, invalid number: ";
                cin >> cust;
            }
            showInfo(account[cust]);
            break;
        case 3:
            break;
        case 4:
            break;
    } while(choice != 5);

    return 0;
}


