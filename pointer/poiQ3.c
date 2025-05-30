// #include<stdio.h>

// int main() {
//     unsigned int x[4][3] = {{1,2,3},{4,5,6},
//                             {7,8,9},{10,11,12}};
//       printf("%u, %u ,%u ", x+3, *(x+3), *(x+2)+3);
//       printf("%d", **(x+3));
//       return 0;

                            
//    }

// pointing to the entire array

 #include<stdio.h>

// int main() {
//     int a[5]= {1,2,3,4,5};
//     int (*p)[5]=&a ;
//     printf(" %d ",p);
//     printf(" %d ", *p+1);
//     printf(" %d ", **p+2);
//     return 0;
// }

int main() {
    int a[5]= {1,2,3,4,5};
    int *p = a ;
    printf(" %d ",p);
    printf(" %d ", *p );
    printf(" %d ", *p+1);
    return 0;

}