#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <fstream>
#include "../json.hpp"
#include "./viewCart.h"
#include "./viewProduct.h"

using json = nlohmann::json;
using namespace std;

class User
{
    ViewProduct viewproduct;
    ViewCart viewcart;
    public:
    void Menu(json data);

};

inline void User::Menu(json data){
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
        viewproduct.viewProducts();
    } else if ( i == 2 ){
        viewcart.viewCart(data);
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



#endif
