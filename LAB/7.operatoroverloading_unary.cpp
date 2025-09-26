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
    Product *cart[10];
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

    friend void addtoCart(Product &p, User &u, int cmax);
    friend void displayCart(User &u, int cmax);
    friend void displayCart(User &u, int cmax, bool detailed);
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
    static int discount;
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
    static void setDiscount(int n)
    {
        discount = n;
    }
    void display()
    {
        cout << "\n-- Product --\nID: " << id << "\nName: " << name
             << "\nDescription: " << description << "\nPrice: " << price
             << "\nStock left: " << stock << "\n\n";
    }

    void operator--()
    {
        if (stock > 0)
        {
            stock--;
        }
        else
        {
            cout << "Stock already zero. Cannot reduce further.\n";
        }
    }

    friend void addtoCart(Product &p, User &u, int cmax);
    friend void displayCart(User &u, int cmax);
    friend void displayCart(User &u, int cmax, bool detailed);
    friend void buy(User &u, int cmax);

} ip1(1, "Iphone 11", "Very good Phone", 10000, 10),
    ip2(2, "Iphone 12", "Very good Phone", 400000, 20),
    ip3(3, "Iphone 13", "Very good Phone", 600000, 40),
    ip4(4, "Iphone 14", "Very good Phone", 900000, 80),
    ip5(ip4, 5);

int Product::discount = 0;

void addtoCart(Product &p, User &u, int cmax)
{
    u.cart[cmax] = &p;
    cout << "Added " << p.name << " to cart.\n";
    Product::discount += p.price * 0.05;

    --p;
}

void displayCart(User &u, int cmax)
{
    if (cmax == 0)
    {
        cout << "\nYour cart is empty!\n";
        return;
    }
    cout << "\n-- Cart Items (Simple View) --\n";
    for (int i = 0; i < cmax; i++)
    {
        cout << "ID: " << u.cart[i]->id << endl
             << " Name: " << u.cart[i]->name << endl
             << " Price: " << u.cart[i]->price << "\n";
    }
}

void displayCart(User &u, int cmax, bool detailed)
{
    if (cmax == 0)
    {
        cout << "\nYour cart is empty!\n";
        return;
    }
    cout << "\n-- Cart Items (Detailed View) --\n";
    for (int i = 0; i < cmax; i++)
    {
        cout << "ID: " << u.cart[i]->id
             << "\nName: " << u.cart[i]->name
             << "\nPrice: " << u.cart[i]->price
             << "\nDescription: " << u.cart[i]->description
             << "\nStock left: " << u.cart[i]->stock << "\n\n";
    }
}

void buy(User &u, int cmax)
{
    if (cmax == 0)
    {
        cout << "\nCart is empty! Cannot proceed with purchase.\n";
        return;
    }
    int count = 0;
    for (int i = 0; i < cmax; i++)
    {
        count += u.cart[i]->price;
    }
    if (count > 10000)
    {
        Product::setDiscount(1000 - (count / 1000));
    }
    cout << "\n-- Order Invoice --\nUser Details";
    cout << "\nName: " << u.name << "\nEmail: " << u.email;
    cout << "\n\nProducts Purchased:";
    displayCart(u, cmax);
    cout << "\nTotal: " << count - (Product::discount) << "\n";
}

int main()
{
    cout << "-- Stack Cart --";
    User a;
    int choice, cmax = 0;
    do
    {
        cout << "\n1. View Profile\n2. View Products\n3. Add To Cart\n4. View Cart\n5. View Cart (Detailed)\n6. BUY CART\n7. View Discount\n8. Exit\n";
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
            cout << "Enter Product Id to add to Cart: ";
            int id;
            cin >> id;
            cin.ignore();
            if (cmax < 10)
            {
                if (id == 1)
                    addtoCart(ip1, a, cmax);
                else if (id == 2)
                    addtoCart(ip2, a, cmax);
                else if (id == 3)
                    addtoCart(ip3, a, cmax);
                else if (id == 4)
                    addtoCart(ip4, a, cmax);
                else if (id == 5)
                    addtoCart(ip5, a, cmax);
                else
                    cout << "Invalid Product ID!\n";
                cmax++;
            }
            else
            {
                cout << "Cart is full!\n";
            }
            break;
        case 4:
            displayCart(a, cmax);
            break;
        case 5:
            displayCart(a, cmax, true);
            break;
        case 6:
            buy(a, cmax);
            break;
        case 7:
            cout << "Current Possible Discount for the products is: " << Product::discount << endl;
            break;
        case 8:
            cout << "Exiting program. Thank you!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 8);
    return 0;
}
