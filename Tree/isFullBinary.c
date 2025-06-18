//Check if Full Binary Tree

#include <stdio.h>
#include <stdlib.h>

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

int isFullBinary(struct Node* root) {
    if (root == NULL)
        return 1;
    if (root->left == NULL && root->right == NULL)
        return 1;
    if (root->left && root->right)
        return isFullBinary(root->left) && isFullBinary(root->right);
    return 0;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    if (isFullBinary(root))
        printf("This is a Full Binary Tree.\n");
    else
        printf("This is NOT a Full Binary Tree.\n");

    return 0;
}
