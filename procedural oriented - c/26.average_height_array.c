#include <stdio.h>
#include <conio.h>

int main()
{
    float a[60], sum = 0.0, avg;
    int n, i;
    printf("Enter the value of n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter Your Height");
        scanf("%f", &a[i]);
    }
    for (i = 0; i < n; i++) 
        sum = sum + a[i];
    avg = (sum / n);
    printf("average height is : %f", avg);

    return 0;
    getch();
}
