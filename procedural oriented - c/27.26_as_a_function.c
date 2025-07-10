#include <stdio.h>
#include <conio.h>

float mean(float a[], int n);

int main() {

    float a[60],avg;
    int i,n;
    printf("Enter the value of n");
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        printf("Enter Your Height :");
        scanf("%f",&a[i]);
    }
    avg = mean(a,n);
    printf("Average is : %f",avg);
    return 0;
}

float mean(float a[], int n) {
    float sum,avg;

    for (int i=0;i<n;i++){
        sum = sum + a[i];
    }
    avg = sum/n;
    return avg;
}