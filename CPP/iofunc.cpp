// we can use the width function to define the width of a field necessary for the output as an item

// precision - by default the floating point numbers are printed with 6 digit after the decimal point however we can 
// specify the no of digits to be displayed after the decimal point while printing the floating point numbers.
// note that unlinke the function width, precision retains the ink effect until its reset 

// filling - we have been printing the values using much larger filed width then required by the value. the unused 
// position of the field are filled iwth white spaces, by default. However we can use the fill functin to fill the unused 
// position by any desired charecter.

// formatting flags / bitfiled and setf - the setf, member function of the ios class can be used for left, right justification 
// and scientific representation 

#include <iostream>
#include <cmath>

using namespace std;
int main() {
    // cout << sqrt(3) << "\n" << 21312.1231 << "\n" << 3.189 << endl;
    cout.precision(3);
    cout.width(100);
    cout.fill('*'); 
    cout.setf(ios::left,ios::adjustfield);
    cout.setf(ios::scientific,ios::floatfield);
    cout << -12.567 << endl;
}