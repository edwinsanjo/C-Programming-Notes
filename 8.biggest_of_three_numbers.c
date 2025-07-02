// write a c programme to find the biggest of three numbers.
#include <stdio.h>

int main() {
    printf("Enter three numbers\n");
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b && a>c){
        printf("a is the biggest number (%d)",a);
    }else if (b>a && b>c) {
        printf("b is the bigger number (%d)",b);
    }else if (c>a && c>b) {
        printf("c is the bigger number (%d)",c);
    }else  {
        printf("no greatest number");
    }
    return 0;
}