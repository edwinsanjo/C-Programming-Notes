#include <iostream>

using namespace std;
class sample {
    float a,b;
    public:
        void getdata();
        friend float mean (sample s);
};
void sample::getdata(){
    cin >>a>>b;
}

float mean(sample s) {
    float t;
    t=(s.a+s.b)/2;
    return t;
}

int main(){
    sample s;
    s.getdata();
    float t;
    t=mean(s);
    cout << t;
    return 0;
}