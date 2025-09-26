#include <iostream>

using namespace std;

class Time {
    int hours;
    int minutes;
    public:
    Time (Time &t){ 
        hours = t.hours;
        minutes = t.minutes;
    }
    void display () {
        cout << hours << ":" << minutes << endl;
    }
    void sum(Time t1,Time t2) {
        hours = (t1.minutes + t2.minutes) / 60;
        minutes = (t1.minutes+t2.minutes) % 60;
        hours = t1.hours + t2.hours + hours ;
        cout << hours << ":" << minutes << endl;

    }
};

int main () {
    // Time t1(5,30); // parameter constructor
    // t1.display();

    // // copy constructor
    // Time t2(t1); // copying value of t1
    // t2.display();

    // // another method for copy constructor
    // Time t3 = t1;
    // t3.display();

    Time *t4 = new Time(1, 50);

    return 0;
}