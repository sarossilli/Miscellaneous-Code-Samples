// Samuel Rossilli
// CS 3060 001
// HW5, P11.8
// Program creates an array of customer structs
// The array of structs can be added to, or updated
// And can be searched for a customer.

#include <iostream>
#include <string>
using namespace std;

struct Customer{
    string name;
    string adress;
    string city, state, zip;
    int phone;
    double balance;
    string lastPay;

};

void getInfo(Customer*);
void showInfo(Customer);
void showSearch(Customer[],string,int);

const int NUM_ACCOUNTS = 7;

int main(){
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
            getInfo(&account[maxCust]);
            maxCust++;
            cout<<endl<<endl;
            break;
        case 2:
            cout << "Customer Number: ";
            cin >> cust;
            while(cust<0||cust>= maxCust){
                cout << "Error, invalid number: ";
                cin >> cust;
            }
            cout << "Enter New Information: " << endl;
            getInfo(&account[cust]);
            cout<<endl<<endl;
            break;
        case 3:
            cout<<"Showing all account info"<<endl;
            for(int i = 0; i<maxCust; i++){
                cout<<endl<<"ACCOUNT " << i+1 << endl;
                showInfo(account[i]);
            }
            cout<<endl<<endl;
            break;
        case 4:
            char input[25];
            cin.ignore( 10000, '\n' );
            cout<<"\nEnter Name to Find: ";
            cin.get(input,25);
            showSearch(account,input,maxCust);
        }
    } while(choice != 5);


    return 0;
}

void getInfo(Customer* account){
    char input[25];
    cin.ignore( 10000, '\n' );
    cout<<"\nEnter Name: ";
    cin.get(input,25);
    account->name = input;

    cin.ignore( 10000, '\n' );
    cout<<"\nEnter Adress: ";
    cin.get(input,25);
    account->adress = input;

    cin.ignore( 10000, '\n' );
    cout<<"\nEnter City: ";
    cin.get(input,25);
    account->city = input;

    cin.ignore( 10000, '\n' );
    cout<<"\nEnter State: ";
    cin.get(input,25);
    account->state = input;

    cin.ignore( 10000, '\n' );
    cout<<"\nEnter Zip Code: ";
    cin >> account->zip;

    cin.ignore( 10000, '\n' );
    cout<<"\nEnter Phone Number: ";
    cin >> account->phone;

    cin.ignore( 10000, '\n' );
    cout<<"\nEnter Account Balance: ";
    cin >> account->balance;
    while(account->balance<0){
        cout<<"\nInvalid entry. Balance must be positive. \nEnter Account Balance: ";
        cin >> account->balance;
    }

    cin.ignore( 10000, '\n' );
    cout<<"\nEnter Date of Last Payment: ";
    cin.get(input,25);
    account->lastPay = input;
}

void showInfo(Customer account){
    cout<< "Account for " << account.name <<endl<<"-------------------"<<endl;
    cout<< "Balance: " << account.balance<< endl;
    cout<< "Adress: " << account.adress << ", "<<account.city << " " << account.state<< " " << account.zip << endl;
    cout << "Phone: " << account.phone <<endl;
    cout<< "Last Payment:" << account.lastPay<<endl;

}

void showSearch(Customer accounts[NUM_ACCOUNTS],string name,int size){
    bool isFound = false;
    int index = 0;
    while(!isFound && index<size){
        if(! name.compare(accounts[0].name)){
            isFound = true;
            cout<<"Account Found!"<< endl<<endl;
            showInfo(accounts[index]);
        }
        index++;
    }
    if(!isFound){
        cout<<"No account was found!"<< endl<<endl;
    }
}
