//deleting the node at a certain position of the list

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void insert_at_end(struct node *head,int data);
void print_list(struct node *head);
struct node* del_at_beg(struct node *head);

//function to delete node at certain position in linked list
void del_at_pos(struct node** head,int pos)
{
    struct node* current = *head;
    struct node* prev = *head;

    if(*head == NULL)
    printf("list is empty");

    else if(pos == 1)
    {
        *head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while(pos!=1)
        {
            prev = current;
            current = current->link;
            pos--;
        }
        prev->link = current->link;
        free(current);
        current = NULL;
    }
}

int main() 
{
struct node* head = (struct node*)malloc(sizeof(struct node*));    
head->data = 45;
head->link = NULL;

insert_at_end(head,3);
insert_at_end(head,96);
insert_at_end(head,7);
insert_at_end(head,9);
printf("list before deletion\n");
print_list(head);

del_at_pos(&head,3);

// head = del_at_beg(head);
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