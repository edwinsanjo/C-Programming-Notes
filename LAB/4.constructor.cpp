#include <iostream>
#include <string>

using namespace std;
class Product;
class User
{
    string name;
    string email;
    string password;
    public:
    Product* cart[10];
    User()
    {
        cout << "Register User\nEnter Your Name \n";
        getline(cin, name);
        cout << "\nEnter Your Email\n";
        getline(cin, email);
        cout << "\nEnter Your Password\n";
        getline(cin, password);
    }
    void viewProfile()
    {
        cout << "\nName: " << name << "\nEmail: " << email;
    }
    friend void addtoCart(Product &p,User &u);
    friend void buy(User &u, int cmax);
};
class Product
{
    int id;
    string name;
    string description;
    int price;
    int stock;

public:
    Product(int ida, string nam, string desc, int pric, int stoc)
    {
        id = ida;
        name = nam;
        description = desc;
        price = pric;
        stock = stoc;
    }
    Product(Product &a, int idx)
    {
        id = idx;
        name = a.name;
        description = a.description;
        price = a.price;
        stock = a.stock;
    }
    void display(){
        cout << "\n-- User Profile --\nName: "<< name<<"\nDescription: "<< description<<"\nPrice: "<< price<<"Stock left: "<< stock<< "\n\n";    }
    
    friend void addtoCart(Product &p,User &u);
    friend void buy(User &u, int cmax);
        
} ip1(1, "Iphone 11", "Very good Phone", 10000, 10),
    ip2(2, "Iphone 12", "Very good Phone", 400000, 20),
    ip3(3, "Iphone 13", "Very good Phone", 600000, 40),
    ip4(4, "Iphone 14", "Very good Phone", 900000, 80),
    ip5(ip4, 5);


void addtoCart(Product &p,User &u,int cmax){
    u.cart[cmax] = &p;
}

void buy(User &u, int cmax){
    cout << "-- Order Invoice --\n User Details";
    cout << "\nName: " << u.name <<"\nEmail: " << u.email;
    cout <<"Product Info";
    for(int i=0; i < cmax;i++){
        cout << "\nID: " << u.cart[i]->id << "\nProduct Name: " << u.cart[i]->name << "\nPrice" << u.cart[i]->price;
    }
}


int main()
{
    cout << "-- Stack Cart --";
    User a;
    int choice,cmax=0;
    do
    {
        cout << "\n1. View Profile\n2.View Products\n3.Add To Cart\n4.BUY CART\n5.\n6. Exit";
        cin >> choice;
        switch (choice)
        {
        case 1:
            a.viewProfile();
            break;
        case 2:
            cout << "View Products\n";
            ip1.display();
            ip2.display();
            ip3.display();
            ip4.display();
            ip5.display();
            break;
        case 3:
            cout << "Enter Product Id to add to Cart";
            int id;
            cin >> id;
            cin.ignore();
            if (cmax<11){
                if (id ==1){
                    addtoCart(ip1,a,cmax);
                } else if (id ==2) {
                    addtoCart(ip2,a,cmax);
                } else if (id ==3){
                    addtoCart(ip3,a,cmax);
                } else if (id ==4){
                    addtoCart(ip4,a,cmax);
                } else if (id == 5){
                    addtoCart(ip5,a,cmax);
                } else {
                    cout << "Invalid Product ID";
                }
                cmax++;
            }
            break;
        case 4:
            buy(a,cmax);
            break;
        case 6:
            cout << "Exiting program. Thank you!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 6);
    return 0;
}