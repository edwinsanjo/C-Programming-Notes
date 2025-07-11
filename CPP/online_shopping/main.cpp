#include <iostream>
#include "./auth/auth.h"
#include "./json.hpp" 
#include "./admin/admin.h"
#include "./user/user.h"
using json = nlohmann::json;

using namespace std;
int main() {
    while (true){
        Auth auth;
        json usrDetails = auth.Authenticate();
         if (usrDetails["type"] == "user"){
            User user;
            user.Menu();
        }else if (usrDetails["type"] == "admin") {
            Admin admin;
            admin.Menu();
        } else if(usrDetails["exit"]){
            return 0;
        }
    }
    return 0;
}