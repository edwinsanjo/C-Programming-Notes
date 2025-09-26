#include <stdio.h>

int main() {
    int n,a=1;
    scanf("%d",&n);
    for (int i = 1; i < (n+1); i++)
    {
        a = a*i;
    }
    printf("%d",a);
    
    return 0;
}