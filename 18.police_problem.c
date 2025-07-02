#include <stdio.h>

int main() {
    int a=0,b=0;
    for (int i = 1; i < 100000; i++)
    {
        a = a+23;
        b=b+i;
        printf("DAY: %d. %d \t %d\n",i,a,b);
        if(a==b) {
            printf("value is %d",a);
            break;
        }
    }
    return 0;
}