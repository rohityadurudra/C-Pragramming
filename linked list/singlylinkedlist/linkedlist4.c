//program to print the data of the linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void print_data(struct node *head);

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
    print_data(head);

    
    return 0;
}
void print_data(struct node *head) {
        int count = 0;
        if (head==NULL){
            printf("Linked list is Empty");
        }
        struct node *ptr = NULL;
        ptr = head;
        while(ptr!=NULL){
            printf(" %d ",ptr->data);
            ptr = ptr->link;
        }
      
    }