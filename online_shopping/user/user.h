#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <fstream>
#include "../json.hpp"

using json = nlohmann::json;
using namespace std;

class User
{
    public:
    void viewProducts();
    void Menu();
    void viewCart();
};

void User::Menu(){
    while (true) {
    int i;
    cout << endl << endl;
    cout << "-- Logged In as User --" << endl;
    cout << "1.Products\n2.Cart\n3.Product Details\n4.Go back";
    cin >> i;
    if (cin.fail()) {
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cout << "Invalid input! Please Try again.\n";
        continue;
    }
    if (i == 1) {
        viewProducts();
    } else if ( i == 2 ){
        viewCart();
    } else if ( i == 3 ) {

    }else if(i == 4){
        break;
        return;
    }else {
        cout << "Invalid Input, Try Again";
        continue;
    }
}
}

json readFromProducts()
{
    ifstream inFile("products.json");
    json data;
    if (inFile.is_open() && inFile.peek() != ifstream::traits_type::eof())
        inFile >> data;
    inFile.close();
    return data;
}

// void writeToFile(const json &data)
// {
//     ofstream outFile("users.json");
//     outFile << data.dump(4);
//     outFile.close();
// }

void User::viewProducts() {
    json data = readFromProducts();
       while (true) {
    int i;
    cout << endl << endl;
    cout << "-- choose view Option -- " << endl;
    cout << "1.View Top 10\n2.View All\n3.View By ID";
    cin >> i;
       if (cin.fail()) {
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cout << "Invalid input! Please Try again.\n";
        continue;
    }
    if (i == 1) {
        for (int i = 0; i < 10; i++)
        {
            cout << "\n\n";
            cout << "ID: " << data[i]["id"] << endl;
            cout << "Name: "<< data[i]["name"] << endl;
            cout << "Description: " << data[i]["description"] << endl;
            cout << "Price: " << data[i]["price"] << endl;
        }
        
    } else if ( i == 2 ){
        for (int i = 0; i < data.size(); i++)
        {
            cout << "\n\n";
            cout << "ID: " << data[i]["id"] << endl;
            cout << "Name: "<< data[i]["name"] << endl;
            cout << "Description: " << data[i]["description"] << endl;
            cout << "Price: " << data[i]["price"] << endl;
        }
    } else if ( i == 3 ) {
        int id;
        cout << "Enter The Product ID: " << endl;
        cin >> id;
        bool j=true;
        for (int i = 0; i < data.size(); i++)
        {
            if(data[i].contains("id") && data[i]["id"] == id){
                cout << "\n\n";
                cout << "ID: " << data[i]["id"] << endl;
                cout << "Name: "<< data[i]["name"] << endl;
                cout << "Description: " << data[i]["description"] << endl;
                cout << "Price: " << data[i]["price"] << endl;
                j=false;
                break;
            }
        }
        if(j){
            cout << "product Not found";        }
    }else {
        cout << "Invalid Input, Try Again";
        continue;
    }
}
}

void User::viewCart(){
        json data = readFromProducts();
       while (true) {
    int i;
    cout << endl << endl;
    cout << "-- choose view Option -- " << endl;
    cout << "1.View Top 10\n2.View All\n3.View By ID";
    cin >> i;
       if (cin.fail()) {
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cout << "Invalid input! Please Try again.\n";
        continue;
    }
    if (i == 1) {
        for (int i = 0; i < 10; i++)
        {
            cout << "\n\n";
            cout << "ID: " << data[i]["id"] << endl;
            cout << "Name: "<< data[i]["name"] << endl;
            cout << "Description: " << data[i]["description"] << endl;
            cout << "Price: " << data[i]["price"] << endl;
        }
        
    } else if ( i == 2 ){
        for (int i = 0; i < data.size(); i++)
        {
            cout << "\n\n";
            cout << "ID: " << data[i]["id"] << endl;
            cout << "Name: "<< data[i]["name"] << endl;
            cout << "Description: " << data[i]["description"] << endl;
            cout << "Price: " << data[i]["price"] << endl;
        }
    } else if ( i == 3 ) {
        int id;
        cout << "Enter The Product ID: " << endl;
        cin >> id;
        bool j=true;
        for (int i = 0; i < data.size(); i++)
        {
            if(data[i].contains("id") && data[i]["id"] == id){
                cout << "\n\n";
                cout << "ID: " << data[i]["id"] << endl;
                cout << "Name: "<< data[i]["name"] << endl;
                cout << "Description: " << data[i]["description"] << endl;
                cout << "Price: " << data[i]["price"] << endl;
                j=false;
                break;
            }
        }
        if(j){
            cout << "product Not found";        }
    }else {
        cout << "Invalid Input, Try Again";
        continue;
    }
}
}


#endif
