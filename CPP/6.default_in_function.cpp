#include <iostream>
using namespace std;

int main() {
    void printline(char ch='*',int n=10);
    printline('=');
    printline();
    printline('$',50);

    return 0;
}

void printline(char ch='*', int n=10) {
int i;
for(i=0;i<n;i++){
    cout << ch;
}
}