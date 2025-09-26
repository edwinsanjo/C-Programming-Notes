#include <iostream>

using namespace std;

void area (int a) {
    cout << "Area Of a Square is : " <<  a*a << endl;
}

void area(int l,int b) {
    cout << "Area of a Rectangle is : " << l*b << endl; 
}

void area (int h, int b1, int b2) {
    float c;
    c = 0.5*h*(b1+b2);
    cout << "Area of a Triangle is : " << c << endl;
}


int main() {

    area(10);
    area(10,20);
    area(10,20,30);
    return 0;
}