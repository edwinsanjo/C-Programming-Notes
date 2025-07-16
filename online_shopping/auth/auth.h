#ifndef AUTH_H
#define AUTH_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>  
#include "../json.hpp"

using json = nlohmann::json;
using namespace std;

class Auth
{
    public:
    json signup();
    json login();
    json Authenticate();
};

json ReadFromFile() {
    ifstream file("users.json");
    json data;

    if (!file.is_open() || file.peek() == ifstream::traits_type::eof()) {
        return json::array(); 
    }

    try {
        file >> data;
        if (!data.is_array()) {
            return json::array(); 
        }
    } catch (...) {
        return json::array(); 
    }

    return data;
}


void WriteToFile(const json &data)
{
    ofstream outFile("users.json");
    outFile << data.dump(4);
    outFile.close();
}

json Auth::Authenticate()
{
    int i;
    for (int i = 0; i < 50; i++) cout << endl;
    cout << "-- Welcome To StackCart --" << endl;
    cout << "1. Login\n2. SignUp\n3.exit\n" << endl;
    while (true){
        cin >> i;
           if (cin.fail()) {
        cin.clear(); 
        cin.ignore(10, '\n'); 
        cout << "Invalid input! Please Try again.\n";
        continue;
    }
        if (i == 1)
        {
            return login();
        }
        else if (i == 2)
        {
            return signup();
        } if (i ==3 ){
            return {{"exit",true}};
        }else {
            continue;
        }
    }
}

json Auth::login()
{
    while (true)
    {

        string email, password;
        json useri;
        bool userFound;
        cout << "\nLogin Page" << endl;
        cout << "\nEnter Your email" << endl;
        cin >> email;

        json data = ReadFromFile();
        for (int i = 0; i < data.size(); ++i) {
            if (data[i].contains("email") && data[i]["email"] == email)
            {
                userFound = true;
                useri=data[i];
                break;
            }
        }
        if(!userFound) {
            cout << "\nUser Not found."<<endl;
            continue;
        };

        cout << "\nEnter Your Password" << endl;
        cin >> password;
        if (useri["password"] == password)
        {
            return useri;
        }
        else
        {
            cout << "wrong password" << endl;
            continue;
        }
    }
}

json Auth::signup()
{
    while (true){
    string name, email, password, phoneno;
    json user;
    bool userExist=false;

    cout << "\nSignup page" << endl;
    cout << "\nEnter Your Name" << endl;
    cin >> name;
    cout << "\nEnter Your email" << endl;
    cin >> email;
    cout << "\nEnter Your Phone number" << endl;
    cin >> phoneno;
    cout << "\nEnter Your Password" << endl;
    cin >> password;
    srand(time(0));
    int id = 10000 + rand() % 90000;
    json newUser = {
        {"id", id},
        {"name", name},
        {"email", email},
        {"phoneno", phoneno},
        {"password", password},
        {"type","user"}
        };
    json data = ReadFromFile();
    for (int i = 0; i < data.size(); ++i) {
        if ((data[i].contains("id")&&data[i]["id"] == id)||
            (data[i].contains("email")&&data[i]["email"] == email)||
            (data[i].contains("phoneno")&&data[i]["phoneno"] == phoneno)) {
    
                cout << "email or phone number not available" << endl;
                userExist=true;
                break;
            }
        }
        if (userExist) {
            continue;
        }
    data.push_back(newUser);
    WriteToFile(data);
    return newUser;
    }
}

#endif