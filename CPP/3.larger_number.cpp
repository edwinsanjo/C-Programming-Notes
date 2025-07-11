#include <iostream>

using namespace std;
class set {
    int m,n;
    public:
        void input();
        void display();
        int largest();
};
void set :: input() {
    cin >> m >> n;
}
int set :: largest () {
    if (m<n) return n;
    return n;
}
void set :: display() {
    cout << largest();
}

int main () {
    set a;
    a.input();
    a.display();
    return 0;
}