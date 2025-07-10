#include <stdio.h>

int sum(int a, int b);
int main()
{
    int n1,n2;
    printf("Enter two two number : \n");
    scanf("%d%d",&n1,&n2);
    printf("\nThe sum is :   %d",sum(n1,n2));
    return 0;
}

int sum(int a,int b) {
    int t = a+b;
    return t;
}