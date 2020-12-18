// Samuel Rossilli
// HW6: P2 11.14
// Program to simulte inventory bins
// User can increase or Decrease bins quantity (max of 30 items per bin)

#include <string>
#include <iostream>
#include <iomanip> 
#include <cstring>
using namespace std;

//Structure of a bin
struct Bin{
    char description[25];
    int quantity;
};
//Number of items/types of bins
const int ITEMS = 10;

//used for formatting table
const int SET_W = 20;


//Function Prototypes
int displayMenu(Bin [ITEMS]);
int selectBin();
void update(Bin*);

int main(){
    //Inventory bins from problem statement
    Bin inventoy[ITEMS] = {
        {"Valve",10},
        {"Bearing",5},
        {"Bushing",15},
        {"Coupling",21},
        {"Flange",7},
        {"Gear",5},
        {"Gear Housing",5},
        {"Vacuum Gripper",25},
        {"Cable",18},
        {"Rod",12}
    };

    int choice;
    int bin;

    choice = displayMenu(inventoy);

    //Loop while not quitting
    while(choice==1){
        bin = selectBin(); //Prompt for which bin

        //Check for valid bin
        while (bin == -1){
            cout << "Invalid Bin. Try Again" << endl;
            bin = selectBin();
        }

        //binChosen is a pointer to the bin, since the function needs to update it
        Bin *binChosen = &inventoy[bin];
        update(binChosen);

        //Reprompt menu
        choice = displayMenu(inventoy);
    }

    return 0;
}

// Function taht displays invenotry list and asks if user wants to quit
int displayMenu(Bin inventory[ITEMS]){
    cout << "Inventory List: " << endl 
        << "-------------------------------------------------------------" << endl
        << "Part Description\tNumber of Parts in the Bin" << endl
        <<"-------------------------------------------------------------" << endl;
    for(int i = 0; i<ITEMS; i++){
        cout <<left << setw(SET_W) <<  inventory[i].description  << right << setw(SET_W) << inventory[i].quantity <<endl;
    }
    cout << endl<<endl;

    int choice = 0;
    cout << "Enter 1 to select a bin. Enter anything else to exit: ";
    cin >> choice;
    cout << endl;

    return choice;
}

// Method that converts user string input into array index
int selectBin(){
    char input[25];
    cin.ignore( 10000, '\n' );
    cout<<"Enter Name of Bin: ";
    cin.get(input,25);
    cout << input<<endl;
    if(!strcmp(input,"Valve")){ return 0;}
    else if (!strcmp(input,"Bearing")){ return 1;}
    else if (!strcmp(input,"Bushing")){ return 2;}
    else if (!strcmp(input,"Coupling")){ return 3;}
    else if (!strcmp(input,"Flange")){ return 4;}
    else if (!strcmp(input,"Gear")){ return 5;}
    else if (!strcmp(input,"Gear Housing")){ return 6;}
    else if (!strcmp(input,"Vacuum Gripper")){ return 7;}
    else if (!strcmp(input,"Cable")){ return 8;}
    else if (!strcmp(input,"Rod")){ return 9;}
    else { return -1;}
}

// Function to update quantities
// Prompts user to increase or decrease and by how much
// Checks for errors in input
void update(Bin *item){
    int choice;
    int val;

    cout << "Enter 0 to Decrease " << item->description << " Inventory or Enter 1 to Increase " << item->description << " Inventory: ";
    cin >> choice;
    cout << endl;

    while(choice>1 || choice<0){
    cout << "Invalid Input" << endl;
    cout << "Enter 0 to Decrease " << item->description << " Inventory or Enter 1 to Increase " << item->description << " Inventory: ";
    cin >> choice;
    cout << endl;
    }

    cout << "Enter by how much: ";
    cin>>val;
    cout << endl;

    while(val<0){
        cout << "Invalid Input. Must be positive" << endl;
        cout << "Enter by how much: ";
        cin>>val;
        cout << endl;
    }
    
    switch (choice)
    {
    case 1:
        while(val+item->quantity > 30 && val>0){
            cout << "Too many items in bucket. Add a max of " << 30-item->quantity << " Items" << endl;
            cout << "Enter by how much to increase: ";
            cin>>val;
            cout << endl;
        }
        item->quantity+=val;
        break;
    
    case 0:
        while(item->quantity-val <0 && val>0){
            cout << "Too few items in bucket. Remove a max of " << item->quantity << " Items" << endl;
            cout << "Enter by how much to decrease: ";
            cin>>val;
            cout << endl;
        }
        item->quantity-=val;
        break;
    }
}