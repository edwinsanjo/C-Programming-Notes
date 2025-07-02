#include <stdio.h>

int sum(int a,int b) {

    return a+b;
}
int main()
{
    int n1,n2;
    printf("Enter two two number");
    scanf("%d%d",&n1,&n2);
    printf("\nThe sum is :   %d",sum(n1,n2));
    return 0;
}
