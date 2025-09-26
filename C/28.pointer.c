#include <stdio.h>

int main() {
    int a=100;
    int *ptr;
    ptr = &a;
    printf("%u\n\n",ptr);
    printf("%u\n\n",*ptr);
    *ptr = *(&a);
    *ptr = 99;
    printf("%u\n\n",&a);
    return 0;   
// }

class item {
    int code;
    float price;
    
}