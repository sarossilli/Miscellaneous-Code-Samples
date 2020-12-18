//10.12
#include <iostream>
using namespace std;

//Global Constants
static int SIZE = 80;
static int MIN = 6;


//Prototypes
void displayRequirements();
void displayResult(char[]);
bool isValid(char[]);
bool hasLength(char[]);
bool hasLowercase(char[]);
bool hasUppercase(char[]);
bool hasDigit(char[]);

int main(){
    char cstring[SIZE];

    //Display Requirements
    displayRequirements();

    //Get user input for password

    cout << "Enter a password: ";
    cin.getline(cstring,SIZE);

    displayResult(cstring);
    return 0;
}

void displayRequirements(){
    cout << "Password Requirements:\n"
    << "The Pasword should be at least " << MIN << "Characters long\n"
    << "The password should have one uppercase and one lowercase\n"
    << "The Password should have one digit.\n\n";
}

void displayResult(char str[]){
    if (isValid(str)){
        cout << "Password is valid\n\n"<<endl;
    }
    else{
        cout << "Invalid password\n\n";
        if( !hasLength(str)){
            cout << "Password does not have " << MIN << " characters"<<endl;
        }
        if ( !hasUppercase(str)){
            cout << "Password does not have at least one uppercase"<<endl;
        }
        if ( !hasLowercase(str)){
            cout << "Password does not have at least one lowercase"<<endl;
        }
        if ( !hasDigit(str)){
            cout << "Password does not have at least one Digit"<<endl;
        }
    }

}

bool isValid(char str[]){
    bool status = false;
    status = hasLength(str) && hasDigit(str) && hasLowercase(str) && hasDigit(str);
    return status;
}

bool hasUppercase(char str[]){
    bool status = false;
    int count = 0;
    while(*str != '\0'){    
        if(isupper(*str)){
            count++;
        }
        *str++;
    }

    if(count>0){
        status = true;
    }

    return status;
}

bool hasLowercase(char str[]){
    bool status = false;
    int count = 0;
    while(*str != '\0'){    
        if(islower(*str)){
            count++;
        }
        *str++;
    }

    if(count>0){
        status = true;
    }
    
    return status;
}

bool hasLength(char str[]){
    bool status = false;
    int count = 0;
    while(*str != '\0'){
        count++;
        *str++;
    }
    if (count>=MIN){
        status = true;
    }
    return status;
}

bool hasDigit(char str[]){
    bool status = false;
    int count = 0;
    while(*str != '\0'){    
        if(isdigit(*str)){
            count++;
        }
        *str++;
    }

    if(count>0){
        status = true;
    }
    
    return status;
}