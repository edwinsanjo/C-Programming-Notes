// // using function overloading
// #include <iostream>

// using namespace std;

// class complexNum{ 
//     int real,imagin;
//     public:
//     void display() {
//         cout << real << ","<< imagin;
//     }
    
//     complexNum() {
//     }
//     complexNum(int a, int b) {
//         real = a;
//         imagin = b;
//     }



//     complexNum operator+(complexNum& a) {
//         a.real = a.real+ real;
//         a.imagin = a.imagin + imagin;
//         return complexNum(a.real, a.imagin);
//     }
// };

// int main() {
//     complexNum a(1,2),b(3,4);
//     complexNum c = a+b;
//     c.display();

//     return 0;
// }










// #include <iostream>

// using namespace std;

// class complexNum{ 
//     int real,imagin;
//     public:
//     void display() {
//         cout << real << ","<< imagin;
//     }
    
//     complexNum() {
//     }
//     complexNum(int a, int b) {
//         real = a;
//         imagin = b;
//     }
//     friend void add(complexNum a, complexNum b);
// };

// void add(complexNum a, complexNum b) {
//     cout << (a.real +b.real) << ", " << (b.imagin+a.imagin);
// }

// int main() {
//     complexNum a(1,2), b(3,4);
//     add(a,b);
// }






// #include <iostream>

// using namespace std;

// class vector {
//     int arr[10];
//     public:
//     vector(){}
//     vector(int a[]) {
//         for (int j = 0; j < 10; ++j)
//             arr[j] = a[j];
//     }
//     vector operator+(vector& b) {
//         int newarr[10];
//         for(int i=0;i<10;i++){
//             newarr[i] = arr[i] + b.arr[i];
//         }
//         return vector(newarr);
//     }
//     void display() {
//         cout << "[";
//         for(int k=0; k<10;k++) {
//             cout<<arr[k]<< ", ";
//         }
//         cout << "]";
//     }
// };

// int main() {
//     int ar[10] = {1,2,3,4,5,6,7,8,9,10};
//     int br[10] = {1,2,3,4,5,6,7,8,9,10};
//     vector a(ar), b(br);
//     vector c = a+b;
//     c.display();
// }




// write a c program to check wether the give number is prime or not

// #include <stdio.h>

// int main() {
//     int num;
//     printf("Enter a number");
//     scanf("%d",&num);
    
//     for(int i =2; i<num;num++) {
//         printf("%d ",num%i);
//         if((num%i) != 0) {
//             printf("The number is not prime");
//             return 0;
//         }
//     }
//     printf("The number is prime");   
// }



// write a c program to give all the prime number in a given ragne

#include <stdio.h>

bool checkprime(int j) {
    for (int i = 0; i < j; i++)
    {
        if(i/j !=0 ) {
            
        }
    }
    
}

int main() {
    int start,end;
    printf("Enter starting number");
    scanf("%d",start);
    printf("end number");
    scanf("%d",end);
    for (int i = start; i < end; i++)
    {
        checkprime(i);
    }
    
}