// 13.4
#include <string>
using namespace std;


class  Person
{
private:
    string name;
    string adress;
    int age;
    string phone;
public:
    Person(){
        name = "";
        adress = "";
        age = 0;
        phone = "";
    }

    Person(string n, string addr, int a, string p){
        name = n;
        adress = addr;
        age = a;
        phone = p;
    }

    void setName(string n){
        name = n;
    }

    void setAddr(string a){
        adress = a; 
    }

    void setAge(int a){
        age = a; 
    }

    void setPhone(string a){
        phone = a; 
    }

    string getPhone(){
        return phone;
    }

    int getAge(){
        return age;
    }

    string getName(){
        return name;
    }

    string getAddr(){
        return adress;
    }
};


int main(){
    Person me ("Meof", "daf" ,1231,"dfawef");

    return 0;
}