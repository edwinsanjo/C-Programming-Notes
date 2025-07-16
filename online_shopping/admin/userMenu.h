#ifndef USERMENU_H
#define USERMENU_H

#include <string>
#include <iostream>
#include <fstream>
#include "../json.hpp"
#include "../auth/auth.h"

using json = nlohmann::json;
using namespace std;

class UserMenu
{
    void EditUser();
    void DeleteUser();
    json readFromUsers();
    
    public:
    void userMenu();
};

json UserMenu::readFromUsers()
{
    ifstream inFile("users.json");
    json data;
    if (inFile.is_open() && inFile.peek() != ifstream::traits_type::eof())
        inFile >> data;
    inFile.close();
    return data;
}


void UserMenu::userMenu()
{
    int i;
    while (true)
    {
        i=0;
        cout << endl;
        cout << "\n1. View Users\n2.Add Users\n3.Edit User\n4.Delete User\n5.Go Back\n";
        cin >> i;
        if (cin.fail()) {
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cout << "Invalid input! Please Try again.\n";
        continue;
    }
        if (i == 1)
        {
            json data = readFromUsers();
            for (int i = 0; i < data.size(); ++i) cout << data[i] << endl;
        }
        else if (i == 2)
        {
            Auth usr;
            usr.signup();
        }
        else if (i == 3)
        {
            EditUser();
        }
        else if (i == 4)
        {
            DeleteUser();
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

void UserMenu::EditUser() {
    json data = readFromUsers();
    int id;
    cout << "Enter user ID to edit: ";
    cin >> id;
    
    bool found = false;

    for (int i = 0; i < data.size(); ++i) {
        if (data[i]["id"] == id) {
            found = true;
            cout << "Editing user with ID: " << id << endl;

            string newName, newEmail;
            cout << "Current Name: " << data[i]["name"] << endl;
            cout << "Enter new name (leave blank to keep current): ";
            cin.ignore();
            getline(cin, newName);

            cout << "Current Email: " << data[i]["email"] << endl;
            cout << "Enter new email : ";
            cin.ignore();
            getline(cin, newEmail);

            if (!newName.empty()) data[i]["name"] = newName;
            if (!newEmail.empty()) data[i]["email"] = newEmail;

            string confirm;
            cout << "Confirm changes? (y/n): ";
            cin >> confirm;

            if (confirm == "y" || confirm == "Y" || confirm == "yes") {
                ofstream outFile("users.json");
                outFile << data.dump(4);
                outFile.close();
                cout << "User updated successfully.\n";
            } else {
                cout << "Edit cancelled.\n";
            }

            break;
        }
    }

    if (!found) {
        cout << " User not found.\n";
    }
}

void UserMenu::DeleteUser()
{
    json data = readFromUsers();
    int id;
    cout << "Enter user ID to delete: ";
    cin >> id;

    bool found = false;
    json updatedUsers = json::array();

    for (int i = 0; i < data.size(); ++i)
    {
        if (data[i]["id"] == id)
        {
            found = true; 
        }
        else
        {
            updatedUsers.push_back(data[i]); 
        }
    }

    if (found)
    {
        string confirm;
        cout << "Confirm Deletion. ID: " << id << ". Type 'y' to confirm or 'n' to cancel: ";
        cin >> confirm;
        if (confirm == "y" || confirm == "Y" || confirm == "yes")
        {
            ofstream outFile("users.json");
            outFile << updatedUsers.dump(4);
            outFile.close();
            cout << "User deleted successfully.\n";
        }
        else
        {
            cout << "Deletion cancelled.\n";
        }
    }
    else
    {
        cout << "User Not Found.\n";
    }
}
#endif
