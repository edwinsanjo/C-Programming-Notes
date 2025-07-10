// write a c programme to calculate the sum of n numbers.
#include <stdio.h>

int main() {
    int n,i=0,sum=0,st;
    printf("You want to add how many numbers ?");
    scanf("%d",&n);
    while ((n-1)>=i) {
        printf("Enter %dth value\n", i+1);
        scanf("%d",&st);
        sum=sum+st;
        i++;
    }
    printf("\n\nYour sum is : %d", sum);
    
    return 0;
}