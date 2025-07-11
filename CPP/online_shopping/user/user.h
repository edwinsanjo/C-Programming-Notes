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
    json signup();
    json login();

public:
    void Menu();
};

void User::Menu(){
    while (true) {
    int i;
    cout << endl << endl;
    cout << "-- Logged In as User --" << endl;
    cout << "1.Products\n2.Manage Products\n3.Manage Orders\n4.Logout";
    cin >> i;
    if (i == 1) {

    } else if ( i == 2 ){

    } else if ( i == 3 ) {

    }else if(i == 4){
        return;
    }else {
        cout << "Invalid Input, Try Again";
        continue;
    }
}
}

// json readFromFile()
// {
//     ifstream inFile("users.json");
//     json data;
//     if (inFile.is_open() && inFile.peek() != ifstream::traits_type::eof())
//         inFile >> data;
//     inFile.close();
//     return data;
// }

// void writeToFile(const json &data)
// {
//     ofstream outFile("users.json");
//     outFile << data.dump(4);
//     outFile.close();
// }


#endif
