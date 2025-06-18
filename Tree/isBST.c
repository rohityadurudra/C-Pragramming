//Check if a Binary Search Tree (BST)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL) return 1;
    if (root->data <= min || root->data >= max) return 0;
    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

int isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);

    if (isBST(root))
        printf("This is a Binary Search Tree.\n");
    else
        printf("This is NOT a Binary Search Tree.\n");

    return 0;
}
