// an abstract class is one that is not used to create an object

#include <iostream>
// making a private member inheritable - we have just seen how to increase the capabilities of an existing class without modifying it
// we have also seen that a private member of a base class cannot be inherited.and therefore its not availble for the derived
// class directly. what do we do if the private data needs to be inherited by a derived class?
// this can be accomplished by modifying the visibility in it of the private member by making it public, thus taking away the 
// advantage of data adding.

// C++ provides a third visibility modifier 'protected', which serve a limited purpose in inheritance. a member declared as protected
// is accessible by the member function within its class and any class immediately derived from it

// when a protected member is inherited in public mode, it becomes protected in derived class too and therefore is accessible 
// by the member function of th derived class. it is also ready for further inheritance. a protected member, inherited in the private
// mode derivation. becomes private in the derived class.

// effect of inheritance

using namespace std;

class student { 
    int rollnumber;
    public:
    void getnumber(int x) ;
    void putnumber();
};
void student::getnumber(int x) {
    rollnumber=x;
}
void student::putnumber() {
    cout << rollnumber;
}

class Test:virtual public student {
    protected: 
        float sub1;
        float sub2;
    public:
    void getmarks(float s1,float s2) {
        sub1 =s1;
        sub2 =s2;
    }
    void putmarks() {
        cout << "Marks \n Sub1 : " << sub1;
        cout << "Sub2 : " << sub2;
    }
};

class Sports:virtual public student {
    protected: 
        int extramark;
    public:
        void getextramark(int x) {
            extramark = x;
        }

};

class Result: public Test, public Sports{
    float total;
    public:
        void display() {
            total = sub1+sub2+extramark;
            cout << "\n\nTotal Marks\n Roll Number: ";
            putnumber();
            cout << "\nTotal Marks: "<< total;
        }
};

int main () {
    
    Result student1;
    student1.getnumber(111);
    student1.getmarks(2,3);
    student1.getextramark(2);
    student1.display();

    return 0;
}