#include <stdio.h>

int main() {
    float a, b;
    scanf("%f%f",&a,&b);
    if(a>b){
        printf("a is bigger(%f)",a);
    }else if(b>a){
        printf("b is bigger (%f)",b);
    }else{
        printf("a = b like god likes(%f = %f)",a,b);
    }
    return 0;
}
// VIMP
// The Law of Trichotomy, in mathematics, states that for any two real numbers, a and b, exactly one of the following is
// true: a is less than b (a < b), a is equal to b (a = b), or a is greater than b (a > b)