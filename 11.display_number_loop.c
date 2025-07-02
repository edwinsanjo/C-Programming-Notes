// display number from 
#include <stdio.h>

int main() {
    int n;
    printf("Enter a number");
    scanf("%d",&n);
    int i=1; // initializing the value (very important for exams)
    while(i<=n) { // the condition
        printf("\n%d",i);
        i++; // modification
    }

    return 0;
}

// three most important part of a loop is 
// 1. initialisation
// 2. condition
// 3. modifications