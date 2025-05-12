//deleting the node at the beginning of the list

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void insert_at_end(struct node *head,int data);
void print_list(struct node *head);
struct node* del_at_beg(struct node *head);

int main() 
{
struct node* head = (struct node*)malloc(sizeof(struct node*));    
head->data = 45;
head->link = NULL;

insert_at_end(head,3);
insert_at_end(head,96);
printf("list before deletion\n");
print_list(head);

head = del_at_beg(head);
printf("list after deletion\n");
print_list(head);

return 0;
}

struct node* del_at_beg(struct node* head)
{
    if(head == NULL)
    printf("list is already Empty");
    
    struct node *ptr = head;
    
    head = head ->link;
    free(ptr);
    ptr = NULL;
    return head;
}

void insert_at_end(struct node* head, int data)
{
    struct node* new = malloc(sizeof(struct node*));
    new->data= data;
    new->link = NULL;

    struct node *ptr = head;
    while(ptr->link!=NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = new; 
}

void print_list(struct node* head)
{
    if(head ==NULL)
    {
        printf("list is empty");
    }
    struct node* ptr ;
    ptr = head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}