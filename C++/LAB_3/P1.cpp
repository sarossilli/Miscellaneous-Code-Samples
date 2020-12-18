// Problem 7.3
//Cips and Salsa
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Function Prototypes
int getTotal(int[],int);
int posOfLargest(int[],int);
int posOfSmallest(int[],int);

int main(){
    //Const number of salsa types
    const int NUM_TYPES = 5;

    //Array of salsa types
    string types[NUM_TYPES] = {"Mild","Medium","Sweet","Hot","Zesty"};

    // Array of Sales Of each Salsa Type
    int sales[NUM_TYPES];

    int totalJarsSold;
    int hiSalesProduct;
    int loSalesProduct;

    //Get The Number of Jars Of  Each Type

    for(int type = 0; type<NUM_TYPES; type++){
        cout << "Input sales for Salsa " << types[type] << ": ";
        cin >> sales[type];
        while(sales[type]<0){
            cout << "Sales must be zero or more. Enter sales for " << types[type] << ": ";
            cin >> sales[type];
        }
    }
    totalJarsSold = getTotal(sales,NUM_TYPES);
    hiSalesProduct = posOfLargest(sales,NUM_TYPES);
    loSalesProduct = posOfSmallest(sales,NUM_TYPES);

    // Display

    cout << endl << endl;
    cout << "Salsa sales report\n\n";
    cout << "Name\t\tJars Sold \n";
    cout << "------------------------" << endl;

    for(int type = 0; type<NUM_TYPES; type++){
        cout  << types[type] << "\t\t" << sales[type]<<endl;
    }

    cout << "Total Sales: " << '\t' << totalJarsSold << endl << endl;
    cout << "High Sales: "  << '\t' << types[hiSalesProduct] << endl;
    cout << "Low Sales: " << '\t' << types[loSalesProduct] << endl;
    return 0;
}


int getTotal(int sales[],int types){
    int sum = 0;
    for(int type = 0; type<types; type++){
        sum+=sales[type];
    }
    return sum;
}

int posOfLargest(int sales[],int types){
    int largest = 0;
    for(int type = 0; type<types; type++){
        if (sales[type] > sales[largest]){
            largest = type;
        }
    }
    return largest;
}

int posOfSmallest(int sales[],int types){
    int smallest = 0;
    for(int type = 1; type<types; type++){
        if (sales[type] < sales[smallest]){
            smallest = type;
        }
    }
    return smallest;
}