#include <iostream>
using namespace std;

class B {
    int a;
    public:
     int b;
     void get_ab();
     int get_a();
     void show_a();
};

class D: private B {
    int c;
    public:
    void mul();
    void display();
};
void B:: get_ab() {
    a = 10;
    b=20;
}

int B::get_a() {
    return 0;
}

void B:: show_a () {
    cout << "a = " << a << endl;
}
void D::mul() {
    c = get_a() * b;
}
void D::display() {
    cout << "a=" << get_a() << endl;
    cout << "b=" << b << endl;
    cout << "c = " << c << endl;
}

// the class d is a public derivation of the base calss b. therefore D inherits all the public of D and retains their visiblity thus 
// a public member of the base class B is also a public member of the derived class D. the private members of B cannot be inherited by D.


int main() {
    D d;
    d.mul();
    d.display();
    return 0;
}