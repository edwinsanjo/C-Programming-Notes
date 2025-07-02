#include <stdio.h>
#include <conio.h>

int main() {
    int i=1, j=1, k=11, count;
    printf("Enter a number\n");
    scanf("%d",&count);
    printf("\nMultiplication Table\n");
    while (i<11) {
        while(j<k){
            printf("%d X %d = %d\n",count, j, (count*j));
            j++;
        }
        getch();
        k=k+10;
        i++;
    }
    return 0;
}