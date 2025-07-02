// write a c programme to calculate the average of 5 numbers
#include <stdio.h>
#include <conio.h>

int main() {
    float a,b,c,d,e,avg;
    printf("Enter 5 numbers\n");
    scanf("%f%f%f%f%f",&a,&b,&c,&d,&e);
    avg = (a+b+c+d+e)/5;
    printf("Average of 5 numbers are : %f",avg);
    return 0;
}