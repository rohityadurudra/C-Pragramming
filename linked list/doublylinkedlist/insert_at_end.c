#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

//creating a node of the doubly linked list
struct node* createnode(int data){
    struct node *head = malloc(sizeof(struct node));
    head->prev = NULL;
    head->data= data;
    head->next = NULL;
    return head;
}
//function to add at the begining of the doubly linked list.
void insert_at_beg(struct node** head,int data)
{    
    struct node *ptr = createnode(data);
    struct node* temp = *head;
    ptr->next = temp;
    temp->prev = ptr;
    temp = ptr;
    *head = temp;
}
//function to add at the end of the dooubly linked list.
//_____________________________________________________________________________
void insert_at_end(struct node* head,int data)
{
    struct node *temp = head;
    struct node *ptr = createnode(data);

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->prev = temp;

}
//____________________________________________________________________________
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

int main()
{
   struct node* head=NULL;
   head = createnode(43);
   insert_at_end(head,6);
   insert_at_end(head,7);
   insert_at_end(head,8);
   insert_at_end(head,9);
   


   
   print_doublylist(head);
   
    return 0;
}