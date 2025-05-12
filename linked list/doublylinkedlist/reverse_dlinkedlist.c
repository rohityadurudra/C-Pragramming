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
//function to delete first element of the linked list
void del_first(struct node** head)
{
    struct node* ptr = *head;
    struct node* temp = ptr;
    ptr = ptr->next;
    ptr->prev = NULL;
    *head = ptr;
    free(temp);
    temp = NULL;
}
//function to delete the last element of the node
void del_last(struct node *head)
{
    struct node *ptr = head;
    struct node *temp = NULL;

    if(head == NULL){
        printf("list is Empty\n");
    }
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    temp = ptr->prev;
    temp->next = NULL;
    ptr->prev = NULL;
    free(ptr);
    ptr = NULL;
}
//fuction to delete node at any position of the doubly linked list
void del_pos(struct node **head , int pos)
{
    struct node* ptr = *head;
    struct node* temp1 = ptr;
    struct node* temp = NULL;

    if(*head == NULL)
    printf("list is already Empty\n");
    if(pos ==1){
        del_first(head);
        return;
    }  
    while(pos>1)
    {
        temp1 = temp1->next;
        pos--;
    }
    if(temp1->next==NULL)
    {
        del_last(*head);
        return;
    }
    else
    {
        temp = temp1->prev;
        temp->next = temp1->next;
        temp1->next->prev = temp;
        temp1->prev = NULL;
        temp1->next = NULL;
        free(temp1);
        temp1 = NULL;
    }
}

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
//function to reverse doubly linked list
//______________________________________________________________________________
struct node* reverse_list(struct node* head)
{
    struct node* ptr1 = head;
    struct node* ptr2 = ptr1->next;

    ptr1->next = ptr1->prev;
    ptr1->prev = ptr2;

    while(ptr2!=NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    // head = ptr1;
    return ptr1;
}
//______________________________________________________________________________
//with print included
void reverse(struct node* head)
{
    // printf("check: %d %d\n",head->data,head->prev->data);
    struct node* ptr = head;
    struct node* tail = NULL;
    // printf("check 1: %d %d\n",ptr->data,ptr->prev->data);
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    // printf("check 2: %d %d\n",ptr->data,ptr->prev->data);
    tail =  ptr;
    //  printf("check 3: %d %d %d\n",ptr->data,head->data,tail->data);
    
    while(tail!=NULL)
    {
        printf("%d ",tail->data);
        tail = tail->prev;
    }
    printf("\n");


}
int main()
{
    struct node* head=NULL;
    head = createnode(89);
    insert_at_end(head,5);
    insert_at_end(head,6);
    // insert_at_end(head,7);
    // insert_at_end(head,8);

    printf("list before reversing\n");
    print_doublylist(head);
    printf("list after reversing\n");

    // struct node* front = head;
    // front = reverse_list(front);
    // print_doublylist(front);
    

    printf("print Method\n");
    reverse(head);

    return 0;
}