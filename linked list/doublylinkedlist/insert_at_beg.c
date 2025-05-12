//creating a node of the doubly linked list

#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

void print_doublylist (struct node* head)
{
    if(head == NULL) {
        printf("list is Empty");
    }
    struct node* ptr = head;
    while(ptr!= NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
//creating a node of the doubly linked list
struct node* createnode(int data){
    struct node *head = malloc(sizeof(struct node));
    head->prev = NULL;
    head->data= data;
    head->next = NULL;
    return head;
}
//______________________________________________________________________________
//finction to add at the begining of the doubly linked list
void insert_at_beg(struct node** head,int data){
    
    struct node *ptr = createnode(data);
    struct node* temp = *head;
    ptr->next = temp;
    temp->prev = ptr;
    temp = ptr;
    *head = temp;
}
//_____________________________________________________________________________
int main()
{
   struct node* head=NULL;
   head = createnode(43);
   insert_at_beg(&head,3);
   insert_at_beg(&head,9);
   insert_at_beg(&head,6);
   insert_at_beg(&head,5);


   
   print_doublylist(head);
   
    return 0;
}