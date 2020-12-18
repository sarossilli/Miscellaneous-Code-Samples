//11.11
#include <iostream>
#include <iomanip>
#include <
using namespace std;

const double HOUSING = 500.0;
const double UTIL = 150.0;
const double HOUSEHOLD = 65.0;
const double TRANSPORTATION = 500.0;
const double FOOD = 150.0;
const double MEDICAL = 65.0;
const double INSURANCE = 500.0;
const double ENTERTAIN = 150.0;
const double CLOTHING = 65.0;
const double MISC = 0.0;

struct Budget
{
    double housing,util,household,
        transportation,food,medical,
        insturance,entertainment,clothing,misc;
};

void getMonthlyBudget(Budget&);
void displayMonthlyReport(const Budget&);

int main(){
    Budget mb;
    getMonthlyBudget(mb);
    displayMonthlyReport(mb);
    return 0;
}

void getMonthlyBudget(Budget& mb){
    cout<<"Enter Housing: "<<endl;
    cin >> mb.housing;
}

void displayMonthlyReport(const Budget& mb){
    cout << setprecision(2) << fixed << showpoint;
    