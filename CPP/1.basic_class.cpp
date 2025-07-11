#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;
class bus_info {
      int bus_id;
      string bus_type;
      int n;
      public:
             void getdata(int bno, string btype, int x);
             void putdata();
};

void bus_info::getdata(int bno, string btype, int x){
     bus_id = bno;
     bus_type=btype;
     n=x;
}

void bus_info::putdata(){
     cout << bus_id << bus_type << n;
}

int main() {
 bus_info x;
 x.getdata(1,"AC",1);
 x.putdata();
 getch();
 return 0;    
}
