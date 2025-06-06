#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

//creating a node of the doubly linked list
struct node* createnode(int data)
{
    struct node *head = malloc(sizeof(struct node));
    head->prev = NULL;
    head->data= data;
    head->next = NULL;
    return head;
}
//function to add at the begining of the doubly linked list.
void insert_at_beg(struct node** head,int data)
{    
    struct node *new = createnode(data);
    struct node* temp = *head;
    new->next = temp;
    temp->prev = new;
    temp = new;
    *head = temp;
}
//function to add at the end of the dooubly linked list.
void insert_at_end(struct node* head,int data)
{
    struct node *temp = head;
    struct node *new = createnode(data);

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;

}
//______________________________________________________________________________
//function to add node at any position i.e between the nodes
void insert_at_pos(struct node* head, int pos, int data)
{
    struct node *prev = NULL;
    struct node *next = head;
    struct node *new = createnode(data);

    while (pos!=1)
    {
        next = next->next;
        pos--;
    }
    prev = next->prev;
    prev->next = new;
    new->prev = prev;
    new->next = next;
    next->prev = new;  
}
//_______________________________________________________________________________
//function to print doubly linked list
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
    printf("\n");
}

int main()
{
   struct node* head=NULL;
   head = createnode(43);
   insert_at_end(head,5);
   insert_at_end(head,6);
   insert_at_end(head,7);

   insert_at_pos(head,3,56);

   print_doublylist(head);

    
   
    return 0;
}