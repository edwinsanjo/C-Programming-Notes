#include <iostream>
#include <string>

using namespace std;

class Student {
    int RegNo;
    string Name;
    float mark1;
    float mark2;
    float mark3;
    float mark4;
    float mark5;
    public:
    Student() {
        cout << "\n\nStudent Registration\n";
        cout << "Enter Your Register Number" << endl;
        cin >> RegNo;
        cout << "Enter Student Name"<< endl;
        cin.ignore();
        getline(cin,Name);
        cout << "Enter Mark1"<< endl;
        cin >> mark1;
        cout << "Enter Mark2"<< endl;
        cin >> mark2;
        cout << "Enter Mark3"<< endl;
        cin >> mark3;
        cout << "Enter Mark4"<< endl;
        cin >> mark4;
        cout << "Enter Mark5"<< endl;
        cin >> mark5;
    }
    void display(){
        cout << "Student Details For " << RegNo<< endl;
        cout << "Student Name : " << Name << endl;
        cout << "Mark 1 : " << mark1 << endl;
        cout << "Mark 2 : " << mark2 << endl;
        cout << "Mark 3 : " << mark3 << endl;
        cout << "Mark 4 : " << mark4 << endl;
        cout << "Mark 5 : " << mark5 << endl;
    }
    void average(int n = 5) {
        if (!mark1 || !mark2 || !mark3 || !mark4 || !mark5) {
            cout << "Mark is not entered please add the marks properly";
        } else {
            int sum = mark1 + mark2 + mark3 + mark4+ mark5;
            cout << "The average is " <<  (sum / n)<< endl;
        }
    }
    void gracemarks() {
        cout << "Which subject to add marks to\n 1. marks1\n2. marks2\n3. marks3\n4. marks4\n5. marks\n";
        int m;
        cin >> m;
        cout << "How much marks to add";
        int gmarks;
        cin >> gmarks;
        if(m ==1) {
            mark1 = mark1 + gmarks;
            cout << "\n Marks1 was Updated the updated mark is : " << mark1<< endl ;
        } else if(m ==1) {
            mark1 = mark1 + gmarks;
            cout << "\n Marks1 was Updated the updated mark is : " << mark1<< endl ;
        } else if(m ==2) {
            mark2 = mark2 + gmarks;
            cout << "\n Marks2 was Updated the updated mark is : " << mark2<< endl ;
        }else if(m ==3) {
            mark3 = mark3 + gmarks;
            cout << "\n Marks3 was Updated the updated mark is : " << mark3<< endl;
        }else if(m ==4) {
            mark4 = mark4 + gmarks;
            cout << "\n Marks4 was Updated the updated mark is : " << mark4<< endl ;
        } else if(m ==5) {
            mark5 = mark5 + gmarks;
            cout << "\n Marks5 was Updated the updated mark is : " << mark5 << endl;
        }
    }
    
};




int main () {
    Student a;
    while (true) {
        cout << endl<< endl << "Student App"<< endl;
        cout << "1.display student\t2.display average marks\t3.add grace marks\t4.exit\n";
        int i;
        cin>> i;

        if (i==1){
            a.display();
        }else if (i==2) {
            a.average();
        } else if (i==3){
            a.gracemarks();
        }else if (i ==4 ) { return 0; }

    }
    return 0;
}