#include<stdio.h>
#include<stdlib.h>

#define MAX 4

int cqueue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data);
int isEmpty();
int isFull();
void printCqueue();

int main() {
    int data;
    while(1) {
    printf("Enter element in queue: ");
    scanf("%d",&data);
    enqueue(data);
    printCqueue();
    }

    return 0;
}

int isFull(){
    if((front==0 && rear == MAX-1) || (front == rear +1))
        return 1; 
    else
        return 0;
    }
int isEmpty() {
    if(front == -1)
        return 1;
    else
        return 0;
}

void enqueue(int data) {

    if(isFull()){
        printf("Queue Overflow \n");
        exit(1);
    }
    
    if(front == -1)
        front  = 0;

    if(rear == MAX-1)
        rear = 0;
    else
        rear = rear + 1;
    cqueue[rear] = data;
}

void printCqueue() {
    int temp;
    if(isEmpty()){
        printf("Queue Underflow\n");
    }
    temp = front;

    if(front <= rear){
        while(temp<=rear){
            printf("%d ",cqueue[temp]);
            temp++;
        }
    }
    else {
        while(temp <= MAX-1){
            printf("%d ",cqueue[temp]);
            temp++;
        }
        temp = 0;
        while(temp <= rear){
            printf("%d ",cqueue[temp]);
            temp++;
        }
    }  
    printf("\n");

}
