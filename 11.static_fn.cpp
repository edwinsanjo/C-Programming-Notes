#include <iostream>
#include <string>

using namespace std;

class User;

class Product
{
    int id;
    string name;
    double price;
    static int discount;

    
public:
    static void setDiscout(int d =0){
        discount = d;
    };
    void createProduct(int pid, string pname, int pprice=10000);
    void displayProducts();
    friend void buyProduct(Product p,User u);
};
void Product::createProduct(int pid, string pname, int pprice)
{
    id = pid;
    name = pname;
    price = pprice;
}
void Product::displayProducts()
{
    cout << "ID :" << id << endl;
    cout << "name :" << name<< endl;
    cout << "price :" << price<< endl << endl;
}

int Product::discount=0;

class User
{
    int id;
    string name;
    string email;
    string address;

public:
    void creatUser();
    friend void buyProduct(Product p,User u);
};

void User::creatUser()
{
    cout << "\n\nUser Registration\n";
    cout << "Enter Your Name\n";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Your Email\n";
    cin.ignore();
    getline(cin, email);
    cout << "Enter Your address\n";
    cin.ignore();
    getline(cin, address);
    cout << "\n\n";
}

void buyProduct(Product p,User u)
{
    if (p.price > 1000) {
        int n = p.price/1000;
        int ghj= n*100;
        Product::setDiscout(ghj);
    }

    cout << "\n\nOrder Invoice\n";
    cout << "Name" << u.name << endl;
    cout << "Email" << u.email<< endl;
    cout << "Address" << u.address<< endl<<endl;
    cout << "Product Detail";
    cout << "Product ID" << p.id << endl;
    cout << "Product " << p.name << endl;
    cout << "Product " << p.price << endl;
    cout << "Order Placed, Thank You\n\n";
}

int main()
{
    Product x, y, z;
    x.createProduct(1, "iphone12", 12006);
    y.createProduct(2, "iphone13", 10302);
    z.createProduct(3, "iphone14");

    x.displayProducts();
    y.displayProducts();
    z.displayProducts();
    while (true)
    {
        int i;
        cout << "\n1.Buy Product\n2.see all products\n3.exit";
        cin >> i;
        if (i == 1)
        {
            User a;
            a.creatUser();
            int id;
            cout << "Enter Your Product Id";
            cin >>id;
            if (id == 1)
            {
                buyProduct(x,a);
            }
            else if (id == 2)
            {
                buyProduct(y,a);
            }
            else if (id == 3)
            {
                buyProduct(z,a);
            }
            else
            {
                cout << "Invalid Product";
            }
        }
        else if (i == 2)
        {
            x.displayProducts();
            y.displayProducts();
            z.displayProducts();
        }
        else if (i == 3)
        {
            return 0;
        }
        else
        {
            cout << "Invalid Input.";
            continue;
        }
    }

    return 0;
}