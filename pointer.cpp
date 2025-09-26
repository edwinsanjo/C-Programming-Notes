// #include <iostream>

// using namespace std;

// class item {
//     int code;
//     float price;
//     public:
//         void getdata(int code,float price) {
//             this->code = code;
//             this->price = price;
//         }  
//         void display() {
//             cout << code << price << endl << endl;
//         }
// };

// int main() {
//     item X;
//     X.getdata(1,100);
//     X.display();

//     item *ptr;
//     ptr=&X;
//     ptr -> getdata(1,100);
//     ptr -> display();
//     // OR
//     // (*ptr).getdata(1,100);
//     // (*ptr).display();

//     return 0;   
// }



















#include <iostream>
using namespace std;

class base {
    public:
    void display() {
        cout << "\n Display Base" ;
    }
    virtual void showoff() {
        cout << "\nShowoff Base";
    }
};

class Derived: public base {
    public:
    void display() {
        cout << "\n Display Derived";
    }
    void showoff() {
        cout << "\n Showoff Derived";
    }
};

int main(){
    base B;
    Derived D;

    base *bptr;
    bptr = &B;
    bptr->display();
    bptr->showoff();
    bptr = &D;
    bptr->display();
    bptr->showoff();


    return 0;
}