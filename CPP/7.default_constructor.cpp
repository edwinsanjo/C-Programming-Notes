#include <iostream>

using namespace std;

class Time {
    int hours;
    int minutes;
    public:
    Time (){ // a constructor without any arguments is called default constructor
        hours = 0;
        minutes = 0;
    }
    void display () {
        cout << hours << minutes;
    }
};

int main () {
    Time t1;
    t1.display();
    return 0;
}