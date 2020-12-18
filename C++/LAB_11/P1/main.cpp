// Sam Rossilli
// Min Max Templates

#include <iostream>
using namespace std;


// Returns minimum of two items
template <class T>
T minimum(T valueOne, T valueTwo){
    if (valueOne<valueTwo){ return valueOne; }
    else { return valueTwo; }
}

// Returns maximum of two items
template <class T>
T maximum(T valueOne, T valueTwo){
    if (valueOne>valueTwo){ return valueOne; }
    else { return valueTwo; }
}

int main(){
    // Test with INTS
    int a = 0;
    int b = 3;
    int r;

    // Should display 0
    cout << "Minimum with ints should return 0, since 0<3" << endl;
    r = minimum(a,b);
    cout << "Minimum returned: " << r << endl << endl;

    // Test with DOUBLES
    double c = 3.4;
    double d = 1.5;
    double k;

    // Should display 3.4
    cout << "Maximum with doubles should return 3.4, since 1.5<3.4" << endl;
    k = maximum(c,d);
    cout << "Maximum returned: " << k << endl;
    return 0;
}
