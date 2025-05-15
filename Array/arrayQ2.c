// //WAP to check whether any of the digit in  a number appears more than once.

// #include<stdio.h>

// void main() {

//     int seen[10] = {0};
//     int N;

//     printf("Enter the number: \n");
//     scanf("%d",&N);

//     int rem;
//     while(N>0) {
//         rem = N%10;
//         if(seen[rem]==1)
//             break;
//         seen[rem] = 1;
//         N = N/10;
//     }

//     if(N>0)
    
//         printf("yes, digit repeats ");
//     else
//         printf("No digit doest not repeat");
// }

#include<stdio.h>

int main() {

    int n, result;
    printf("Enter a number: ");
    printf("\n");
    scanf("%d",&n);
    result = n%100;
    printf("result is: %d ");
    return 0; 


}