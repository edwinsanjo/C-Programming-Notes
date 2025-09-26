#include <iostream>
using namespace std;

// Base class
class Gshape 
{
protected:
    double dim1, dim2;  
public:
      void getdata(double dim1, double dim2=1) {
        this->dim1=dim1;
        this->dim2=dim2;
    }

    // Virtual function to compute and display area
    virtual void displayarea() { }
	
};

// Derived class for Triangle
class Triangle : public Gshape {
public:
    void displayarea() {
        double area = 0.5 * dim1 * dim2;
        cout << "Area of Triangle = " << area << endl;
    }
};

// Derived class for Rectangle
class Rectangle : public Gshape {
public:
    void displayarea()  {
        double area = dim1 * dim2;
        cout << "Area of Rectangle = " << area << endl;
    }
};
class Circle : public Gshape {
public:
    void displayarea()
    {
        double area = 3.14 *dim1 * dim1;
        cout << "Area of Circle = " << area << endl;
    }
};

// Main function
int main() {
	Gshape B;
    Gshape *s;   // Base class pointer
    int choice;

    cout << "Choose a shape to calculate area:\n";
    cout << "1. Triangle\n2. Rectangle\n3.Circle\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        Triangle t;
        s = &t;
        cout << "Enter base and height of triangle:\n";
        s->getdata(5.25,10.9);
        s->displayarea();
    }
    else if (choice == 2) {
        Rectangle r;
        s = &r;
        cout << "Enter length and breadth of rectangle:\n";
        s->getdata(10.15, 6.75);
        s->displayarea();
    }
    else if(choice==3){
         Circle c;
        s = &c;
        cout << "Enter radius of circle:\n";
        s->getdata(10.15,3.14);
        s->displayarea();
    }
    else
     { cout << "Invalid input";
     }

    return 0;
}