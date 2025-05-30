#include<stdio.h>

// int main() {
//     int a[5] = {1,2,3,4,5};
//     int(*p)[5] = &a;
//     printf("%d",p);
//     return 0;
// }
// int main() {
//     int a[5] = {1,2,3,4,5};
//     int *p = a;
//     printf("%d", *p);
//     return 0;
// }

int main() {
    int a[5] = {1,2,3,4,5};
    int(*p)[5] = &a;
    printf("%d\n", p);
    printf("%d\n", **p);
    printf("%d\n", *p);
    printf("%d\n", *p + 1);
    printf("%d", **p + 1);
    return 0;
}