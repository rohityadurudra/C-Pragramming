#include<stdio.h>

void main() {

    int a = 5;
    int *p = &a;

    printf("%d\n",a);
    printf("%d\n",p);
    printf("%d\n",&a);
    printf("%d\n",&p);
    printf("%d\n",*p);
}