//default, parametreized and copy constructors
#include <iostream>
#include <string>
using namespace std;

class User {
    string name;
    string email;
    string address;
    public:
    User() {
        cout << "USER REGISTRATION \nName: ";
        getline(cin,name);
        cout << "\nEmail:";
        cin >> email;
        cout << "\nAddress";
        getline(cin,address);
    }
    void display() {
        cout << "\n\n VIEW USER\nName : "<< name<<"\nEmail : "<<email<<"\nAddress : "<<address;
    }
};

class Product{
    int id;
    string name;
    int price;
    public:
    Product() {
        cout << "USER CREATION \nName: ";
        cin>>id;
        cout << "\nEmail:";
        cin >> name;
        cout << "\nAddress";
        cin>>price;
    }
};