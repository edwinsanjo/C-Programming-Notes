#include <stdio.h>

int main(){
    int n,m=15,i;
    scanf("%d",&n);
    scanf("%d",&m);
    while(n<=m){
        for(i=1;i<=10;i++){
            printf("%d * %d = %d\n",i,n,(i*n));
        }
        printf("\n\n");
        n++;
    }
    return 0;
}