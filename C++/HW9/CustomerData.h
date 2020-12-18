#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include "PersonData.h"

using namespace std;

//inherits from person data
class CustomerData: public PersonData
{
private:
    int customerNumber;
    bool mailingList;
public:
    CustomerData(/* args */);
    bool isMailing();
    int getCustomerNumber();
    void setCustomerNumber(int);
    void setMailingList(bool);
};

//constructor
CustomerData::CustomerData()
{
    mailingList = true;
    customerNumber = 0;
}

//getters
bool CustomerData::isMailing(){
    return mailingList;
}

int CustomerData::getCustomerNumber(){
    return customerNumber;
}

//setters
void CustomerData::setCustomerNumber(int id){
    customerNumber = id;
}

void CustomerData::setMailingList(bool val){
    mailingList = val;
}



#endif