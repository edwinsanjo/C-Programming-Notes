#include <stdio.h>
#include <conio.h>

int main() {
    int age;
    printf("VOTING ELIGIBILITY CHECKER\n");
    printf("Enter Your Age\n");
    scanf("%d",&age);
    if(age<18) {
        printf("Sorry to say that you are not eligible\n");
        printf("wait %d more years to vote",(18-age));
    }else {
        printf("You are eligible to vote\n");
        printf("Please carry on inside");
    }
    return 0;
}