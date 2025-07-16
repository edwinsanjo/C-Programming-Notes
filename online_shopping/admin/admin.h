#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <iostream>
#include <fstream>
#include "../json.hpp"
#include "./userMenu.h"
#include "./productMenu.h"


using json = nlohmann::json;
using namespace std;

class Admin
{
    void EditUser();
    void DeleteUser();
    void userMenu();
    // void productsMenu();
    // void ordersMenu();

public:
    void Menu();
};

void Admin::Menu()
{
    int i;
    UserMenu usermenu;
    ProductMenu productmenu;
    while (true)
    {
        cout << endl;
        cout << "-- Logged In as Admin --" << endl;
        cout << "1.Manage Users\n2.Manage Products\n3.Manage Orders\n4.Logout\n";
        cin >> i;
        if (i == 1)
        {
            usermenu.userMenu();
        }
        else if (i == 2)
        {
            productmenu.productMenu();
        }
        else if (i == 3)
        {
        }
        else if (i == 4)
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