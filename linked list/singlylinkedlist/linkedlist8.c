//program to add element at the begining of the linked list without returning the pointer to head
//insertion at the begining of the linked list

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link; 
};

void add_beg(struct node **head,int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = NULL;
    ptr->link = *head;
    *head = ptr;
}

int main() {
    struct node *head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data= 45;
    head->link= NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr->data=98;
    ptr->link = NULL;

    head->link = ptr;

    int data = 3;
    add_beg(&head, data);
    ptr = head;

    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }

    // while(head!=NULL){
    //     printf("%d ",head->data);
    //     head= head->link;
    // }
    return 0;
}
