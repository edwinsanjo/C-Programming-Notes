#include <stdio.h>
#include <conio.h>

int option;

void menu();
int income_tax(int inc);
void multiplication(int m,int n);
int  main() {
    int tax,m,n,salary;
    do {
        menu();
        switch(option){
                       
                       case 1 :
                            printf("Enter the salary\n");
                            scanf("%d",&salary);
                            tax = income_tax(salary);
                            printf("\nYour Tax is : %d \n\n",tax);
                            break;
                       case 2: 
                            printf("\nEnter the value of m and n");
                            scanf("%d%d",&m,&n);
                            multiplication(m,n);
                            break;               
                       case 3:
                            break; 
        }
        } while (option != 3);
    getch();
    return 0;
}

void menu() {
     printf("1- Income Tax");
     printf("\n2- Multiplication Table");
     printf("\nEnter Your Choice\n");
     scanf("%d",&option);
     }

int income_tax(int inc) 
{
    int tax;
    if(inc>=00 && inc<=400000) {
               tax=0;
    } else if (inc>=400001 && inc<=800000){
        tax = (0.05*(inc - 400000));
    } else if (inc>=800001 && inc<=1200000){
        tax = 0 + 20000 + (0.1*(inc - 800000));
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

void multiplication(int m, int n){
    int i;
    while(m<=n){
        for(i=1;i<=10;i++){
            printf("%d * %d = %d\n",i,m,(i*m));
        }
        printf("\n\n");
        m++;
    }
}