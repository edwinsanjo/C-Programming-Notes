#include <iostream>

using namespace std;
class item{
    int number;
    float price;
    public:
        void input();
        void display();
};

void item::input() {
    cin >> number >> price;
}
void item::display() {
    cout << number << endl;
    cout << price << endl;
}

int main(){
    item x,y; 
    x.input();
    x.display();

    y.input();
    y.display();
    return 0;
}