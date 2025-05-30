#include<stdio.h>

void main() {

    int x = 10 , *p, *q;
    p = &x;
    q = p;
    printf("%d %d", *p, *q);
}