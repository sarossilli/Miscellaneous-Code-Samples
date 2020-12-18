#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
const int NUM_DRINKS = 5;

struct Drink
{
    string name;
    double price;
    int num;
};

int getChoice(Drink []);
void transaction(Drink [], int, double &);

int main(){
    int choice;
    double earnings = 0;

    Drink machine[NUM_DRINKS]{

    };
    cout << fixed << showpoint << setprecision(2);

    choice = getChoice();
    while (choice !=5)
    {
        transaction(machine,choice,earnings);
        choice = getChoice(machine);
    }

    cout << "Total Earnings: $" << earnings << endl;
    return 0;
    
}

int getChoice(Drink m[]){
    int choice;
    cout<<endl;

    for (int x = 0; x< NUM_DRINKS; x++){
        cout << (x+1) << "> " << m[x].name << "\t\t" << m[x].price << endl;
    }

    cout << (NUM_DRINKS+1);
    cout << "choose one:" 
    cin >> choice;

    while(choice<1 || choice>6){
        cout << "choose one:";
        cin >> choice;
    }
    return 0;
}

void transaction(Drink m[], int choice, double &earnings){
    double money;

    if (m[choice].num == 0){

    }

    cout << "enter money ";
    cin>> money;

    while(money < m[choice].price || money > 1.0){
        cout << "enter money ";
        cout >> money;
    }

    if (money>=m[choice].price){
        cout<< "SODA OUT"<<endl;
        cout << "RETURN " << (money - m[choice].price);
    }

    earnings += m[choice].price;
    m[choice].num--;

}