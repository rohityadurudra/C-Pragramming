#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node* add_at_end(struct node *head,int data){
    struct node *ptr, *temp;
    ptr = head;

    temp = malloc(sizeof(struct node));
    temp->data=data;
    temp->link = NULL;

    while(ptr->link!=NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
    return head;
}
//function to delete node at the end of the linked list

void del_at_last(struct node *head){
    struct node *temp = head;
    struct node *temp2 = head;
    while(temp->link!=NULL) {
        temp2 = temp;
        temp  = temp->link;    
    } 
    temp2->link = NULL;
    free(temp);
    temp = NULL;
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
int main() {

struct node *head = (struct node*)malloc(sizeof(struct node));
head->data= 45;
head->link= NULL;

struct node *ptr;
ptr = head;

ptr = add_at_end(head,98);
ptr = add_at_end(head,6);
del_at_last(head);
ptr = head;

while(ptr!=NULL){
    printf(" %d ",ptr->data);
    ptr= ptr->link;
}

return 0;
}