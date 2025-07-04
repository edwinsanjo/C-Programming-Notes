// Write a programme to add two numbers.
#include <stdio.h>
#include <conio.h>

int main(){
    int a,c,b; // defining variables (int -> intiger, char ->)
    printf("Enter the value of a : ");
    scanf("%d",&a);
    printf("Enter the value of b : ");
    scanf("%d",&b);
    c = a + b;
    printf("The sum of a and b is : %d",c);
    return 0;
}