// write a c++ programme to read a list containing item name, item code and price.
// interactively and produce a 3 column output as shown below

// Name            Code        Price 
// Turbo C++       1001        250.95
// C KNS           905         95.70
// note that the name and code are left justified
// and the price is right justified with a precision of 2 digits.
// trailing zeros are shown above
#include <iostream>
#include <string>

using namespace std;

class data {
    string name;
    int code;
    double price;
    public:
    data(string n, int c, double p) {
        name = n;
        code = c;
        price = p;
    };
    friend void display(data d);
};


void display(data d) {
    cout.setf(ios::left,ios::adjustfield);
    cout << d.name;
    cout.width(20);
    cout.setf(ios::left,ios::adjustfield);
    cout << d.code;
    cout.width(20);
    cout.precision(2);
    cout.setf(ios::right,ios::adjustfield);
    cout << d.price;
    
    cout << "\n";
}

int main() {
    data a("Turbo C++",1001,250.95),b("C KNS",905,95.70);
    cout.setf(ios::left,ios::adjustfield);
    cout << "Name";
    cout.width(20);
    cout.setf(ios::left,ios::adjustfield);
    cout << "Code";
    cout.width(20);
    cout.precision(2);
    cout.setf(ios::left,ios::adjustfield);
    cout << "Price\n";
    display(a);
    display(b);

    return 0;
}
