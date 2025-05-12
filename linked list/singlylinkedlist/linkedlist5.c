//program to insert data at the end of the list

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void add_at_end(struct node *head,int data);
// void print_data(struct node *head);

int main() {
    
    struct node *head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *current = NULL;
    current = malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 3;
    current->link = NULL;

    head->link->link = current;
    add_at_end(head,67);
    // print_data(head);


    printf("%d",head->link->link->link->data);

    
    return 0;
}

void add_at_end(struct node *head,int data){
    struct node *ptr, *temp;
    ptr = head;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link = NULL;

    while(ptr->link!=NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
}
// void print_data(struct node *head) {
//         int count = 0;
//         if (head==NULL){
//             printf("Linked list is Empty");
//         }
//         struct node *ptr = NULL;
//         ptr = head;
//         while(ptr!=NULL){
//             printf(" %d ",ptr->data);
//             ptr = ptr->link;
//         }
      
//     }