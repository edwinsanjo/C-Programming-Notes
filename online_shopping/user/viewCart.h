#ifndef VIEWCART_H
#define VIEWCART_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "../json.hpp"

using json = nlohmann::json;
using namespace std;

class ViewCart
{
public:
    void viewCart(json data);
};

inline json readFromCart()
{
    ifstream inFile("cart.json");
    json data;
    if (inFile.is_open() && inFile.peek() != ifstream::traits_type::eof())
        inFile >> data;
    inFile.close();
    return data;
}
inline json readFromProduct()
{
    ifstream inFile("products.json");
    json data;
    if (inFile.is_open() && inFile.peek() != ifstream::traits_type::eof())
        inFile >> data;
    inFile.close();
    return data;
}
inline json readFromUsers()
{
    ifstream inFile("users.json");
    json data;
    if (inFile.is_open() && inFile.peek() != ifstream::traits_type::eof())
        inFile >> data;
    inFile.close();
    return data;
}

inline json readFromOrders()
{
    ifstream inFile("users.json");
    json data;
    if (inFile.is_open() && inFile.peek() != ifstream::traits_type::eof())
        inFile >> data;
    inFile.close();
    return data;
}

inline void ViewCart::viewCart(json datai)
{
    json products = readFromProduct();
    json users = readFromUsers();
    json carts = readFromCart();
    json orders = readFromOrders();
    while (true)
    {
        int i;
        cout << endl
             << endl;
        cout << "-- choose Cart Option -- " << endl;
        cout << "1.Add By Id\n2.View All\n3.Buy Cart\n4.Go back";
        cin >> i;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please Try again.\n";
            continue;
        }
        json prod;
        if (i == 1)
        {
            int id;
            cout << "\n\nEnter Your Product ID: ";
            cin >> id;
            json cartData;
            for (int a = 0; a < carts.size(); a++)
            {
                if (carts[a]["user"].contains("id") && carts[a]["user"]["id"] == datai["id"])
                {
                    json cartData = carts[i];
                }
                else
                {
                    srand(time(0));
                    int id = 10000 + rand() % 90000;
                    cartData = {
                        {"id", id},
                        {"user", datai},
                        {"products", {}},
                    };
                }
            }
            for (int j = 0; j < products.size(); j++)
            {
                if (products[i].contains("id") && products[i]["id"] == id)
                {
                    prod = products[i];
                    cout << datai;
                }
            }
            cartData["products"].push_back(prod);
            carts.push_back(cartData);

            ofstream outFile("cart.json");
            outFile << carts.dump(4);
            outFile.close();
        }
        else if (i == 2)
        {
            for (int k = 0; k < carts.size(); k++)
            {
                if (carts[k]["user"].contains("id") && carts[k]["user"]["id"] == datai["id"])
                {
                    for (int b = 0; b < carts[k]["products"].size(); b++)
                    {
                        cout << "\n\n";
                        cout << "ID: " << carts[k]["products"][b]["id"] << endl;
                        cout << "Name: " << carts[k]["products"][b]["name"] << endl;
                        cout << "Description: " << carts[k]["products"][b]["description"] << endl;
                        cout << "Price: " << carts[k]["products"][b]["price"] << endl;
                    }
                    break;
                }
            }
        }
        else if (i == 3)
        {
            json cartDataa;
            int price=0;
            for (int l = 0; l < carts.size(); l++)
            {
                if(carts[l]["user"].contains("id") && carts[l]["user"]["id"] == datai["id"]){
                    cartDataa = carts[l];
                }
            }
            for(int a=0;a<cartDataa["products"].size();a++){
                price = price + stoi(cartDataa["products"][a]["price"].get<string>());
            }
            string confirm;
        cout << "Confirm Purchase. Price: " << price << ". Type 'y' to confirm or 'n' to cancel: ";
        cin >> confirm;
        if (confirm == "y")
        {
            orders.push_back(cartDataa);
            ofstream outFile("orders.json");
            outFile << orders.dump(4);
            outFile.close();
        }
        else
        {
            cout << "\ncancelled.\n";
        }
            
        }
        else  if (i == 4)
        {
            for (int k = 0; k < orders.size(); k++)
            {
                if (orders[k]["user"].contains("id") && orders[k]["user"]["id"] == datai["id"])
                {
                    for (int b = 0; b < orders[k]["products"].size(); b++)
                    {
                        cout << "\n\n";
                        cout << "ID: " << orders[k]["products"][b]["id"] << endl;
                        cout << "Name: " << orders[k]["products"][b]["name"] << endl;
                        cout << "Description: " << orders[k]["products"][b]["description"] << endl;
                        cout << "Price: " << orders[k]["products"][b]["price"] << endl;
                    }
                    break;
                }
            }
        }else  if (i == 5)
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

#endif
