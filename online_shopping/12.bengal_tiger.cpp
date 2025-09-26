#include <iostream>

// programming language inspired by python developed by kn saravanan sir with C++ as the base.

using namespace std;

class INT {
    int x;
    public:
    INT(){x=0;}
    void operator++(){ // for ++obj
        x=x+1;
    }
    void operator++(int ) {
        x=x+1;
    }
    void operator-(){
        x=-x;
    }
    void display() {
        cout << x<<endl;
    }
};

int main(){
    INT x;
    x.display();
    ++x;
    x.display();
    x++;
    x.display();
    -x;
    x.display();
    return 0;
}