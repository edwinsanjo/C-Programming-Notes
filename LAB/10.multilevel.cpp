#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
protected:
    string productName;
    double price;

public:
    Product(string name, double p) {
        productName = name;
        price = p;
    }

    void displayProduct() const {
        cout << "Product Name: " << productName << endl;
        cout << "Price: $" << price << endl;
    }

    double getPrice() const {
        return price;
    }

    string getName() const {
        return productName;
    }
};

class User {
protected:
    string name;
    string email;
    string address;

public:
    User() {
        cout << "Enter user name: ";
        cin >> name;
        cout << "Enter Email: ";
        cin >> email;
        cout << "Enter Address: ";
        cin >> address;
    }

    void displayUser() const {
        cout << "User Name: " << name << endl;
        cout << "User Email: " << email << endl;
    }
};

class Cart {
protected:
    vector<pair<Product, int>> items; 

public:
    void addToCart(Product& p, int qty) {
        items.push_back(make_pair(p, qty));
    }

    void displayCart() const {
        cout << "\nCart Contents:\n";
        for (const auto& item : items) {
            item.first.displayProduct(); 
            cout << "Quantity: " << item.second << endl;
            cout << "Subtotal: $" << item.first.getPrice() * item.second << endl;
            cout << "---------------------------------\n";
        }
    }

    double getTotalPrice() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.first.getPrice() * item.second;
        }
        return total;
    }
};

class Order : public Cart, public User {
public:
    Order(Product p, int qty, User u) : User(u) {
        addToCart(p, qty); 
    }

    void generateInvoice() const {
        displayUser();
        cout << endl;

        displayCart();

        cout << "\nTotal Price: $" << getTotalPrice() << endl;
    }
};

void showMenu() {
    cout << "\nMENU\n";
    cout << "1. View Products\n";
    cout << "2. Add Product to Cart\n";
    cout << "3. View Cart\n";
    cout << "4. Buy (Generate Invoice)\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    User user;
    Product product1("Laptop", 899.99);
    Product product2("Shoes", 49.99);
    Product product3("Headphones", 199.99);

    Order* order1 = nullptr; 

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:

                cout << "\nAvailable Products:\n";
                product1.displayProduct();
                product2.displayProduct();
                product3.displayProduct();
                break;

            case 2:
                
                int productChoice, quantity;
                cout << "\nSelect a product to add to cart (1- Laptop, 2- Shoes, 3- Headphones): ";
                cin >> productChoice;
                cout << "Enter Quantity: ";
                cin >> quantity;

                switch (productChoice) {
                    case 1:
                        order1 = new Order(product1, quantity, user); 
                        break;
                    case 2:
                        order1 = new Order(product2, quantity, user); 
                        break;
                    case 3:
                        order1 = new Order(product3, quantity, user); 
                        break;
                    default:
                        cout << "Invalid product choice!\n";
                        break;
                }
                break;

            case 3:
                // View cart
                if (order1 != nullptr) {
                    cout << "Your Cart:\n";
                    order1->displayCart(); 
                } else {
                    cout << "Your cart is empty!\n";
                }
                break;

            case 4:
                if (order1 != nullptr) {
                    cout << "Generating invoice...\n";
                    order1->generateInvoice();
                } else {
                    cout << "No orders found! Please add a product to the cart first.\n";
                }
                break;

            case 5:
                cout << "Exiting the program.\n";
                return 0;

            default:
                cout << "Invalid choice! Please select a valid option.\n";
                break;
        }
    }
}