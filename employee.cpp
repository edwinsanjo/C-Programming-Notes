#include <iostream>
#include <string>

using namespace std;

class Employee {
    int id;
    string name;
    int entry;
    int exit;
    public:
    Employee(){}
    Employee(int idA, string nameA, int h1A, int m1A,int h2A, int m2A) {
        id = idA;
        name = nameA;
        entry = (h1A*60)+m1A;
        exit = (h2A*60)+m2A;
    }
    int isLate() {
        if((exit-entry)>=(8*60)){
            return id;
        }else {
            return 0;
        }
    }
    int getID() { return id; }
};

int main() {
    int max = 10;
    Employee a[max];
    int Late[10];
    int LateNum = 0;
    int notLate[10];
    int notLateNum = 0;
    for(int n=0; n<max;n++){
        int id=101;
        int h1= 7;
        int h2= 8;
        a[n]((id+n),"Edwin",(h1+n),30,h2,30);
    }
    for (int i = 0; i < max; i++)
    {
        int id = a[i].getID();
        int isLate = a[i].isLate();
        if(isLate == 0) {
            notLate[notLateNum];
            notLateNum++;
        }
        if(isLate > 100) {
            Late[LateNum];
            LateNum++;
        }
    }
    cout << Late;
    cout << notLate;

}