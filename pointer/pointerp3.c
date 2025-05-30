#include<stdio.h>

int main() {
    int a[] = {5,16,7,89,45,32,23,10};
    int *p = &a[2];
    // printf("%d", *(--p));
    printf("%d", *(p--));
    printf("%d", *p);
    return 0;
}