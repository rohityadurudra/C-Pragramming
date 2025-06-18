//Check if Complete Binary Tree

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int isCompleteBinary(struct Node* root) {
    if (root == NULL)
        return 1;

    struct Node* queue[MAX];
    int front = 0, rear = 0;
    int flag = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        if (current == NULL) {
            flag = 1;
        } else {
            if (flag)
                return 0;
            queue[rear++] = current->left;
            queue[rear++] = current->right;
        }
    }
    return 1;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    if (isCompleteBinary(root))
        printf("This is a Complete Binary Tree.\n");
    else
        printf("This is NOT a Complete Binary Tree.\n");

    return 0;
}
