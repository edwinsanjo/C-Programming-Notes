#include <iostream>
#include <conio.h>

using namespace std;

class INT {
    int x;
    public:
    INT() {
        x=0;
    }
    INT (int a) {
        x=a;
    }
    void display() {
        cout << x<< endl;
    }
    INT operator-(INT y) {
        INT temp;
        temp.x = x-y.x;
        return temp;
    }
    INT operator*(INT y) {
        INT temp;
        temp.x = x*y.x;
        return temp;
    }
    INT operator/(INT y) {
        INT temp;
        temp.x = x/y.x;
        return temp;
    }
    INT operator%(INT y) {
        INT temp;
        temp.x = x%y.x;
        return temp;
    }

friend INT operator+(INT X, INT Y) {
       INT temp;
       temp.x = X.x + Y.x;
       return temp;       
       }
};
int main() {
    INT x(10), y(20), z,a,b,c,d;
    z = x+y;
    z.display();
    a=x-y;
    a.display();
    b=x*y;
    b.display();
    c=x/y;
    c.display();
    d=x%y;
    d.display();
    
    getch();
    return 0;
}
