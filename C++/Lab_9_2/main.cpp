#include <iostream>
#include <iomanip>

#include "FinalExam.h"
using namespace std;

int main(){
    int questions;
    int missed;

    cout << "How many q;s are on the final";
    cin >> questions
    cout << "Missed? "
    cin>> missed

    FinalExam test(questions,missed);

    cout << setprecision(2) << fixed;
    cout << "the grade is:" << test.getLetterGrade() <<endl;

    return 0;
}