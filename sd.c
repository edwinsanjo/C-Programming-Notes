// write a c program to check wether a give numbeer is angstrong or not
#include <stdio.h>
#include <math.h>

int  main() {
    printf("Enter a Number :");
    int num,j,ans;
    scanf("%d",&num);
    while(num!=0) {

        j = num%10;
        ans = ans + j*j*j;
        num = num/10;
    }
    printf("Answer is : %d", ans);
    return 0;
}