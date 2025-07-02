#include <stdio.h>

int factorial(int a) {
    int fact=1,i;
    for ( i =1 ; i <= a; i++)
    {
        fact = fact * i;
    }
    
}

int main () {
    int n,f;
    printf("Enter the value of n");
    scanf("%d",&n);
    f=factorial(n);
    printf("factorial of %d (%d!) is %d",n,n,f);
    return 0;
}