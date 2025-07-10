// write a c program to display the odd numbers from 1 - 100
#include <stdio.h>

int main() {
    int n, i=0;
    printf("Enter a number");
    scanf("%d",&n);
    while (i<=n) {
        printf("%d\n",i);
        i=i+2;
    }
    return 0;
}