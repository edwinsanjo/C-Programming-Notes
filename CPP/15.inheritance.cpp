#include <iostream>

using namespace std;

class M {
    public:
        void display() {
            cout << "Class M" << endl;
        }
};
class N:public M {
    public:
        void display(){
            cout << "Class N";
        }

};
int main() {
    N x;
    x.display();
    x.M::display();
    return 0;
}












// #include <iostream>

// using namespace std;

// class M {
//     public:
//         void display() {
//             cout << "Class M" << endl;
//         }
// };
// class N {
//     public:
//         void display(){
//             cout << "Class N";
//         }

// };
// class MN: public M,public N{
//     public:
//     void display() {
//         M::display();
//     }
// };
// int main() {
//     MN x;
//     x.display();
//     return 0;
// }