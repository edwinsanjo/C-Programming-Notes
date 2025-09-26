// the header file iomanip provides a set of functions called manipulators which can be used to manipulate the output 
// formats they provide the same features as that of the ios member functions and flags.
//   | Manipulators          | meaninig                                          | equalent
//   | setw(int w)           | set the field width to w                          | width()
//   | setprecision(intd);   | set the floating point precision to d             | precision()
//   | setfill(int c)        |                                                   | fill()
//   | setflags(flag f)      | set the format flag f                             | setf()
//   | resetiosflags(long f) |  reset the flags                                  | unsetf();

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

// int main() {
//     cout << setw(200) << 12345<< endl << setprecision(2) <<1.321423<<endl
//      << setw(2) << setprecision(4) << sqrt(2) << endl << setiosflags(ios::scientific)
//     << sqrt(3) << endl;

//     cout.setf(ios::showpoint);
//     cout << setw(5) << "n" << setw(15) << "Inverse of n" << setw(15) << "Sum of terms \n\n";
//     double term, sum = 0;
//     for (int n=1;n<=10;n++) {

//         term = 1.0/float(n);
//         sum = sum+term;
//         cout << setw(5) << n << setw(14)<<setprecision(4)<< setiosflags(ios::scientific)<< term << setw(13) << resetiosflags(ios::scientific)
//         sum  << endl;
//     }

//     return 0;
// }



ostream& currency(ostream& output) {
    output << "Rs .";
    return output;
}

ostream& form(ostream& output) {
    output.setf(ios::showpos)
}