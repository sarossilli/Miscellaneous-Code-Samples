// 12.15
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

int countSentances(string);
int countWords(string);

int main(){
    int sentances;
    int words;
    double average;

    string file = "text.txt";
    words = countWords(file);
    sentances = countSentances(file);

    average = static_cast<double>(words)/sentances;

    cout << "The file contains" << words << " words and" << sentances << " sentances." << endl;
    cout << "AVG: " << setprecision(1) << fixed << average << endl;

    return 0;
}

int countSentances(string filename){
    const int SIZE = 500;
    char input[SIZE];
    fstream file;

    file.open(filename,ios::in);
    if (!file){
        cout << "File Not Found";
        exit(0);
    }

    file.getline(input,SIZE);
    while(!file.eof()){
        for(int i = 0; input[i] != '\0', i++){
            if(inpu)
        }
    }
    file.close();
}

int countWords(string filename){
    
}