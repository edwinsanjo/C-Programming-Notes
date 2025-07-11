#include <stdio.h>

int main() {
    float sum;
    int i,n;

    printf("Enter a number.");
    scanf("%d",&n);

    for (i=1;i<=n;i++) {
        sum=sum+(1.0/i);
    }
    printf("%f",sum);

    return 0;
}