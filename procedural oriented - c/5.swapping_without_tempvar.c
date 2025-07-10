// write a c program to swap two numbers without a temporary variable
#include <stdio.h>
#include <conio.h>
int main() {
    int a,b;
    printf("Enter Two numbers\n");
    scanf("%d%d",&a,&b);
    printf("\nBefore :\n\t n1 = %d \t n2 = %d",a,b);
    a = a+b;
    b = a-b;
    a = a-b;
    printf("\n\nAfter :\n\t n1 = %d \t n2 = %d",a,b);
    return 0;
}