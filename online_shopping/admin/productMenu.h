#ifndef PRODUCTMENU_H
#define PRODUCTMENU_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime> 
#include "../json.hpp"
#include "../auth/auth.h"

using json = nlohmann::json;
using namespace std;

class ProductMenu
{
    void EditProduct();
    json CreateProduct();
    void DeleteProduct();
    json readFromProducts();
    
    public:
    void productMenu();
};

json ProductMenu::readFromProducts()
{
    ifstream inFile("products.json");
    json data;
    if (inFile.is_open() && inFile.peek() != ifstream::traits_type::eof())
        inFile >> data;
    inFile.close();
    return data;
}


void ProductMenu::productMenu()
{
    
    int i;
    while (true)
    {
        i=0;
        cout << endl;
        cout << "\n1. View Products\n2.Add Products\n3.Edit Products\n4.Delete Products\n5.Go Back\n";
        cin >> i;
    if (cin.fail()) {
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cout << "Invalid input! Please Try again.\n";
        continue;
    }

        if (i == 1)
        {
            json data = readFromProducts();
            for (int i = 0; i < data.size(); ++i) cout << data[i] << endl;
        }
        else if (i == 2)
        {
            CreateProduct();
        }
        else if (i == 3)
        {
            EditProduct();
        }
        else if (i == 4)
        {
            DeleteProduct();
        }
        else if (i == 5)
        {
            return;
        }
        else
        {
            cout << "Invalid Input, Try Again";
            continue;
        }
    }
}

json ProductMenu::CreateProduct(){
     while (true){
    string name, description, price, rating;
    json product;
    bool productExist=false;

    cout << "\n Create Product Page" << endl;
    cout << "\nEnter Product Name" << endl;
    cin.ignore();
    getline(cin, name);
    cout << "\nEnter Product Description" << endl;
    cin.ignore();
    getline(cin, description);
    cout << "\nEnter Product Price" << endl;
    cin.ignore();
    getline(cin, name);
    cout << "\nEnter Product Rating" << endl;
    cin.ignore();
    getline(cin, rating);
    srand(time(0));
    int id = 10000 + rand() % 90000;
    json newProduct = {
        {"id", id},
        {"name", name},
        {"description", description},
        {"price", price},
        {"rating", rating},
        };
    json data = readFromProducts();

    for (int i = 0; i < data.size(); ++i) {
            if ((data[i].contains("id") && data[i]["id"] == id))
            {
                cout << "Try Again" << endl;
                productExist=true;
                break;
            }
        }
        if (productExist) {
            cout << "Product already Exist";
            continue;
        }
    data.push_back(newProduct);
    ofstream outFile("products.json");
    outFile << data.dump(4);
    outFile.close();
    cout << "Product created successfully.";
    return newProduct;
}
}

void ProductMenu::EditProduct(){
    json data = readFromProducts();
    int id;
    cout << "Enter user ID to edit: ";
    cin >> id;
    
    bool found = false;

    for (int i = 0; i < data.size(); ++i) {
        if (data[i]["id"] == id) {
            found = true;
            cout << "Editing user with ID: " << id << endl;

            string newName, newDescription;
            cout << "Current Name: " << data[i]["name"] << "\n";
            cout << "Enter new name (leave blank to keep current): ";
            cin.ignore();
            getline(cin, newName);

            cout << "Current description: " << data[i]["description"] << "\n";
            cout << "Enter new description (leave blank to keep current): ";
            cin.ignore();
            getline(cin, newDescription);

            if (!newName.empty()) data[i]["name"] = newName;
            if (!newDescription.empty()) data[i]["description"] = newDescription;

            string confirm;
            cout << "Confirm changes? (y/n): ";
            cin >> confirm;

            if (confirm == "y" || confirm == "Y" || confirm == "yes") {
                ofstream outFile("products.json");
                outFile << data.dump(4);
                outFile.close();
                cout << "Product updated successfully.\n";
            } else {
                cout << "Edit cancelled.\n";
            }

            break;
        }
    }

    if (!found) {
        cout << " product not found.\n";
    }
}

void ProductMenu::DeleteProduct()
{
    json data = readFromProducts();
    int id;
    cout << "Enter product ID to delete: ";
    cin >> id;

    bool found = false;
    json updatedProducts = json::array();

    for (int i = 0; i < data.size(); ++i)
    {
        if (data[i]["id"] == id)
        {
            found = true; 
        }
        else
        {
            updatedProducts.push_back(data[i]); 
        }
    }

    if (found)
    {
        string confirm;
        cout << "Confirm Deletion. ID: " << id << ". Type 'y' to confirm or 'n' to cancel: ";
        cin >> confirm;
        if (confirm == "y" || confirm == "Y" || confirm == "yes")
        {
            ofstream outFile("products.json");
            outFile << updatedProducts.dump(4);
            outFile.close();
            cout << "Product deleted successfully.\n";
        }
        else
        {
            cout << "Deletion cancelled.\n";
        }
    }
    else
    {
        cout << "Product Not Found.\n";
    }
}

#endif
