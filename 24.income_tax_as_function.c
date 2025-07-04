#include <stdio.h>

int calculate_income_tax(int inc);
int main() {
    int inc,tax;
    // printf("How may times to run the programme");
    // scanf("%d",num);
    for (int i = 1; i <= 60; i++)
    {
        printf("Enter your salary \n");
        scanf("%d",&inc);
        tax = calculate_income_tax(inc);
        printf("\nYour Income Tax Will Be : %d\n",tax);
    }
    return 0;
}

int calculate_income_tax(int inc) {
    int tax;
    if(inc>=00 && inc<=400000) {
        tax = 0;
    } else if (inc>=400001 && inc<=800000){
        tax = (0.05*(inc - 400000));
    } else if (inc>=800001 && inc<=1200000){
        tax = 20000 + (0.1*(inc - 800000));
    } else if (inc>=120001 && inc<=1600000){
        tax = 60000 + (0.15*(inc - 1200000));
    } else if (inc>=160001 && inc<=200000){
        tax = 120000 + (0.2*(inc - 1600000));
    } else if (inc>=200001 && inc<=240000){
        tax = 200000 + (0.25*(inc - 2000000));
    } else if (inc>=240001){
        tax = 300000+ (0.3*(inc - 2400000));
    }
    return tax;
}