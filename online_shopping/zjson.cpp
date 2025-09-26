#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"  // nlohmann/json

using namespace std;
using json = nlohmann::json;

const string FILENAME = "products.json";

// Function to read JSON from file
json readFromFile() {
    ifstream inFile(FILENAME);
    json data;
    if (inFile.is_open() && inFile.peek() != ifstream::traits_type::eof())
        inFile >> data;
    inFile.close();
    return data;
}

// Function to write JSON to file
void writeToFile(const json& data) {
    ofstream outFile(FILENAME);
    outFile << data.dump(4);
    outFile.close();
}

// Create (Add new product)
void createProduct() {
    json data = readFromFile();

    int id;
    string name;
    float price;

    cout << "Enter product ID: ";
    cin >> id;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter price: ";
    cin >> price;

    json newProduct = {
        {"id", id},
        {"name", name},
        {"price", price}
    };

    data.push_back(newProduct);
    writeToFile(data);
    cout << "Product added.\n";
}

// Read (Display all products)
void readProducts() {
    json data = readFromFile();

    cout << "\n📦 All Products:\n";
    for (auto& product : data) {
        cout << "ID: " << product["id"] << ", Name: " << product["name"]
             << ", Price: ₹" << product["price"] << endl;
    }
}

// Update product by ID
void updateProduct() {
    json data = readFromFile();
    int id;
    cout << "Enter product ID to update: ";
    cin >> id;

    bool found = false;
    for (auto& product : data) {
        if (product["id"] == id) {
            string newName;
            float newPrice;

            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, newName);
            cout << "Enter new price: ";
            cin >> newPrice;

            product["name"] = newName;
            product["price"] = newPrice;

            found = true;
            break;
        }
    }

    if (found) {
        writeToFile(data);
        cout << "✅ Product updated.\n";
    } else {
        cout << "❌ Product not found.\n";
    }
}

// Delete product by ID
void deleteProduct() {
    json data = readFromFile();
    int id;
    cout << "Enter product ID to delete: ";
    cin >> id;

    bool found = false;
    json updatedData;

    for (auto& product : data) {
        if (product["id"] != id) {
            updatedData.push_back(product);
        } else {
            found = true;
        }
    }

    if (found) {
        writeToFile(updatedData);
        cout << "🗑️ Product deleted.\n";
    } else {
        cout << "❌ Product not found.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- E-Commerce Product CRUD ---\n";
        cout << "1. Create Product\n";
        cout << "2. View All Products\n";
        cout << "3. Update Product\n";
        cout << "4. Delete Product\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createProduct(); break;
            case 2: readProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: cout << "👋 Exiting...\n"; break;
            default: cout << "❗ Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}