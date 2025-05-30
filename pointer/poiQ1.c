//reversing a series of number using pointers

#include<stdio.h>
#define N 5
int main() {
    int a[N], *p;
    printf("Enter elements of the array: ", N);
    for(p=&a[0];p<=a+N-1;p++){
        scanf("%d",p);
    }

    for(p=a+N-1; p>=a; p--){
        printf(" %d ", *p);
    }
return 0;
}