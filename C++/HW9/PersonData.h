#ifndef PERSONDATA_H
#define PERSONDATA_H


#include <string>
using namespace std;

class PersonData
{
private:
    string lastName, firstName, adress, city, state;
    int zip,phone;

public:
    PersonData();
    PersonData(string,string,string,string,string,int,int);
    //Getters
    string getLastName();
    string getFirstName();
    string getAdress();
    string getCity();
    string getState();
    int getZip();
    int getPhone();
    
    //Setters
    void setLast(string);
    void setFirst(string);
    void setAdress(string);
    void setCity(string);
    void setState(string);
    void setZip(int);
    void setPhone(int);
};

PersonData::PersonData()
{
}
PersonData::PersonData(string fn, string ln, string adr, string cty, string st, int z, int p)
{
    firstName = fn;
    lastName = ln;
    adress = adr;
    city = cty;
    state = st;
    zip = z;
    phone = p;
}
//getters
string PersonData::getLastName(){
    return lastName;
}
string PersonData::getFirstName(){
    return firstName;
}
string PersonData::getAdress(){
    return adress;
}
string PersonData::getCity(){
    return city;
}
string PersonData::getState(){
    return state;
}
int PersonData::getZip(){
    return zip;
}
int PersonData::getPhone(){
    return phone;
}
// Setters
void PersonData::setLast(string ln){
    lastName = ln;
}
void PersonData::setFirst(string fn){
    firstName = fn;
}
void PersonData::setAdress(string adr){
    adress = adr;
}
void PersonData::setCity(string cty){
    city = cty;
}
void PersonData::setState(string st){
    state = st;
}
void PersonData::setZip(int z){
    zip = z;
}
void PersonData::setPhone(int p){
    phone = p;
}

#endif