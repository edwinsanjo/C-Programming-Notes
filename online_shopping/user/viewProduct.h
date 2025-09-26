#ifndef VIEWPRODUCT_H
#define VIEWPRODUCT_H

#include <string>
#include <iostream>
#include <fstream>
#include "../json.hpp"

using json = nlohmann::json;
using namespace std;

class ViewProduct
{
    public:
    void viewProducts();
};

json readFromProducts()
{
    ifstream inFile("products.json");
    json data;
    if (inFile.is_open() && inFile.peek() != ifstream::traits_type::eof())
        inFile >> data;
    inFile.close();
    return data;
}

void ViewProduct::viewProducts() {
    json data = readFromProducts();
       while (true) {
    int i;
    cout << endl << endl;
    cout << "-- choose view Option -- " << endl;
    cout << "1.View Top 10\n2.View All\n3.View By ID\n4.Go back";
    cin >> i;
       if (cin.fail()) {
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cout << "Invalid input! Please Try again.\n";
        continue;
    }
    if (i == 1) {
        for (int a = 0; a < 10; a++)
        {
            cout << "\n\n";
            cout << "ID: " << data[a]["id"] << endl;
            cout << "Name: "<< data[a]["name"] << endl;
            cout << "Description: " << data[a]["description"] << endl;
            cout << "Price: " << data[a]["price"] << endl;
        }
        
    } else if ( i == 2 ){
        for (int d = 0; d < data.size(); d++)
        {
            cout << "\n";
            cout << "ID: " << data[d]["id"] << endl;
            cout << "Name: "<< data[d]["name"] << endl;
            cout << "Description: " << data[d]["description"] << endl;
            cout << "Price: " << data[d]["price"] << endl;
        }
    } else if ( i == 3 ) {
        int id;
        cout << "Enter The Product ID: " << endl;
        cin >> id;
        bool dsa=true;
        for (int j = 0; j < data.size(); j++)
        {
            if(data[j].contains("id") && data[j]["id"] == id){
                cout << "\n\n";
                cout << "ID: " << data[j]["id"] << endl;
                cout << "Name: "<< data[j]["name"] << endl;
                cout << "Description: " << data[j]["description"] << endl;
                cout << "Price: " << data[j]["price"] << endl;
                dsa=false;
                break;
            }
        }
        if(dsa){
            cout << "product Not found";        }
    }else if(i==4){
        return;
    }else{
        cout << "Invalid Input, Try Again";
        continue;
    }
}
}

#endif
