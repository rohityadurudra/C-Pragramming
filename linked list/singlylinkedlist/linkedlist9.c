//inserting node in the linked list at a certain position

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link; 
};
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
//function to add a element at certain position
void add_at_pos(struct node* head,int data, int position){
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data= data;
    ptr2->link = NULL;
 
    while(position!=2){
        ptr = ptr->link;
        position--;
    }
    ptr2->link = ptr->link;
    ptr->link=ptr2;
}
int main() {
     struct node *head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data= 45;
    head->link= NULL;

    add_at_end(head,98);
    add_at_end(head,3);
    
    int data = 67, position = 3;
    add_at_pos(head,data,position);
    
    struct node *ptr = head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}