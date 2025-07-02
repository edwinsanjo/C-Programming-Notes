#include <stdio.h>

int main(){
    int n,count=15,i;
    scanf("%d",&n);
    scanf("%d",&count);
    while(n<=count){
        for(i=1;i<=10;i++){
            printf("%d * %d = %d\n",i,n,(i*n));
        }
        printf("\n\n");
        n++;
    }
    return 0;
}