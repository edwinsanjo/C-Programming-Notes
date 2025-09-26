#include <iostream>
#include <string>
using namespace std;

class Product;

class User {
    string name;
    string email;
    string password;

public:
    Product* cart[10];
    int cmax;

    User() {
        cmax = 0;
        cout << "Register User\nEnter Your Name \n";
        getline(cin, name);
        cout << "\nEnter Your Email\n";
        getline(cin, email);
        cout << "\nEnter Your Password\n";
        getline(cin, password);
    }

    void viewProfile() {
        cout << "\nName: " << name << "\nEmail: " << email;
    }

    User& operator+=(Product &p);  
    User& operator-=(Product &p);   

    friend void buy(User &u);
    friend class Product;
};

class Product {
public:
    int id;
    string name;
    string description;
    int price;
    int stock;
    static int discount;

    Product(int ida, string nam, string desc, int pric, int stoc) {
        id = ida;
        name = nam;
        description = desc;
        price = pric;
        stock = stoc;
    }

    Product(Product &a, int idx) {
        id = idx;
        name = a.name;
        description = a.description;
        price = a.price;
        stock = a.stock;
    }

    static void setDiscount(int n) {
        discount = n;
    }

    void display() {
        cout << "\nID: " << id
             << "\nName: " << name
             << "\nDescription: " << description
             << "\nPrice: " << price
             << "\nStock left: " << stock << "\n";
    }
} ip1(1, "Iphone 11", "Very good Phone", 10000, 10),
  ip2(2, "Iphone 12", "Very good Phone", 400000, 20),
  ip3(3, "Iphone 13", "Very good Phone", 600000, 40),
  ip4(4, "Iphone 14", "Very good Phone", 900000, 80),
  ip5(ip4, 5);

int Product::discount = 0;

User& User::operator+=(Product &p) {
    if (cmax < 10) {
        cart[cmax++] = &p;
        cout << p.name << " added to cart.\n";
    } else {
        cout << "Cart full!\n";
    }
    return *this;
}

User& User::operator-=(Product &p) {
    for (int i = 0; i < cmax; i++) {
        if (cart[i]->id == p.id) {
            cout << cart[i]->name << " removed from cart.\n";
            for (int j = i; j < cmax - 1; j++) {
                cart[j] = cart[j + 1];
            }
            cmax--;
            return *this;
        }
    }
    cout << p.name << " not found in cart.\n";
    return *this;
}

void buy(User &u) {
    int count = 0;
    for (int i = 0; i < u.cmax; i++) {
        count += u.cart[i]->price;
    }
    if (count > 10000) {
        Product::setDiscount(1000 - (count / 1000));
    }
    cout << "\n-- Order Invoice --\nUser Details";
    cout << "\nName: " << u.name << "\nEmail: " << u.email;
    cout << "\nProduct Info";
    for (int i = 0; i < u.cmax; i++) {
        cout << "\nID: " << u.cart[i]->id
             << "\nProduct Name: " << u.cart[i]->name
             << "\nPrice: " << u.cart[i]->price << "\n";
    }
    cout << "Total: " << count - (Product::discount) << "\n";
}

int main() {
    cout << "-- Stack Cart --\n";
    User a;
    int choice;

    do {
        cout << "\n1. View Profile\n2. View Products\n3. Add To Cart\n4. Remove From Cart\n5. Buy Cart\n6. Exit\n";
        cin >> choice;

        switch (choice) {
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
            case 3: {
                cout << "Enter Product Id to add to Cart: ";
                int id;
                cin >> id;
                if (id == 1) a += ip1;
                else if (id == 2) a += ip2;
                else if (id == 3) a += ip3;
                else if (id == 4) a += ip4;
                else if (id == 5) a += ip5;
                else cout << "Invalid Product ID\n";
                break;
            }
            case 4: {
                cout << "Enter Product Id to remove from Cart: ";
                int id;
                cin >> id;
                if (id == 1) a -= ip1;
                else if (id == 2) a -= ip2;
                else if (id == 3) a -= ip3;
                else if (id == 4) a -= ip4;
                else if (id == 5) a -= ip5;
                else cout << "Invalid Product ID\n";
                break;
            }
            case 5:
                buy(a);
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
