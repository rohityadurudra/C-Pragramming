//Check if AVL Tree

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

int height(struct Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL) return 1;
    if (root->data <= min || root->data >= max) return 0;
    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

int isAVL(struct Node* root) {
    if (root == NULL) return 1;

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) > 1)
        return 0;

    return isAVL(root->left) && isAVL(root->right) &&
           isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);

    if (isAVL(root))
        printf("This is an AVL Tree.\n");
    else
        printf("This is NOT an AVL Tree.\n");

    return 0;
}
