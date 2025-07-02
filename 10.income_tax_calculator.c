#include <stdio.h>

int main() 
{
    int inc,tax;
    printf("Enter your salary in lakhs");
    scanf("%d",&inc);

    if(inc>=00 && inc<=400000) {
        printf("your tax is 0");

    } else if (inc>=400001 && inc<=800000){

        tax = (0.05*(inc - 400000));
        printf("tax : %d",tax);

    } else if (inc>=800001 && inc<=1200000){

        tax = 0 + 20000 + (0.1*(inc - 800000));
        printf("tax %d",tax);

    } else if (inc>=120001 && inc<=1600000){

        tax = 60000 + (0.15*(inc - 1200000));
        printf("tax %d",tax);

    } else if (inc>=160001 && inc<=200000){

        tax = 120000 + (0.2*(inc - 1600000));
        printf("tax %d",tax);

    } else if (inc>=200001 && inc<=240000){

        tax = 200000 + (0.25*(inc - 2000000));
        printf("tax %d",tax);

    } else if (inc>=240001){

        tax = 300000+ (0.3*(inc - 2400000));
        printf("tax %d",tax);
        
    } else if ( inc < 0 )
    return 0;
}