//Sam Rossilli
#include "CustomerData.h"
#include <iostream>

using namespace std;

int main(){
    //Creating a CustomerData object that is a child class of PersonData
    CustomerData data;

    // Can access inherited PersonData's member functions
    data.setFirst("Bob");
    cout << data.getFirstName() << endl;

    // Can access CustomerData member Funcions
    data.setMailingList(true);
    cout << data.isMailing() << endl;

    return 0;
}