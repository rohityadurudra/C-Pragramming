//instertion at the end of an array when array is not full
#include<stdio.h>

int add_at_end(int a[],int freepos, int data);

int main() {
    int a[10];
    int i,n,freepos;
    printf("enter the number of elements of an array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    freepos = n;
    // freepos = add_at_end(a,freepos,65);
    a[freepos]= 65;
    freepos++;

    for(i=0;i<freepos;i++){
    printf("%d",a[i]);
}
}
// int add_at_end(int a[],int freepos, int data){
//     a[freepos] = data;
//     freepos++;
//     return freepos;
// }
