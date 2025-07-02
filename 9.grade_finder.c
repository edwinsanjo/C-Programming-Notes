// a programme to find outstanding

#include <stdio.h>

int main() {
    int m;
    printf("Enter Your Mark\n");
    scanf("%d",&m);
    if(m<=100 && m>=91) {
        printf("Your marks are O(outstanding)");
    } else if(m<=90 && m>=81){
        printf("Your grade is E (Excellent)");
    } else if(m<=80 && m>=71){
        printf("Your grade is D (Distinction)");
    } else if(m<=70 && m>=61){
        printf("Your grade is F (First Class)");
    } else if(m<=60 && m>=41){
        printf("Your grade is P (Pass)");
    } else if(m<=40 && m>=0){
        printf("Your Failed");
    }else {
        printf("Invalid Mark");
    }

    return 0;
}