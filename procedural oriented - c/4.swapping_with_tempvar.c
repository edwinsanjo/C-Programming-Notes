// write a c program to swap two numbers with a temporary variable
#include <stdio.h>

int main() {
    int a,b,temp;
    printf("Enter two number\n");
    scanf("%d%d",&a,&b);
    printf("\nBefore :\n\t n1 = %d \t n2 = %d",a,b);
    temp = a;
    a = b;
    b = temp;
    printf("\n\nAfter :\n\t n1 = %d \t n2 = %d",a,b);

    return 0;
}