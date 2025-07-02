#include <stdio.h>

int main() {
    int p,i=1;
    printf("Enter a number\n");
    scanf("%d", &p);
    printf("\nMultiplication Table of %d is \n",p);
while (i<11) {
    printf("%d X %d = %d\n",p,i,(i*p) );
    i++;
};

    return 0;
}