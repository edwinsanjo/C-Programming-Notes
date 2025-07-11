#include <stdio.h>

int main() {
    int day;
    while ( 1 == 1)
    {
        if(day == 0) break;   
        printf("Enter a number for finding the day\n");
        scanf("%d\n",&day);
        switch (day)
        {
            case 1: printf("Monday\n");break;
            case 2: printf("Tuesday\n");break;
            case 3: printf("Wednesday\n");break;
            case 4: printf("Thursday\n");break;
            case 5: printf("Friday\n");break;
            case 6: printf("Saturday\n");break;
            case 7: printf("Sunday\n");break;
            default:printf("Hmmm; saravanan sir will beat you.\n");break;
        }
    }
    return 0;
}