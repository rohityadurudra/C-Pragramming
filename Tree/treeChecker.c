/*Here is a menu-driven C program that allows you to:

                       Create a binary tree manually

                       Check if the tree is:

                       Binary Search Tree (BST)

                       AVL Tree

                       Full Binary Tree

                       Complete Binary Tree*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

#define MAX 100

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Manually insert nodes to form tree (BST for simplicity)
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// ---------- Check BST ----------
bool isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL) return true;
    if (root->data <= min || root->data >= max) return false;
    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}
bool isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// ---------- Check AVL ----------
int height(struct Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}
bool isAVL(struct Node* root) {
    if (root == NULL) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1)
        return false;
    return isAVL(root->left) && isAVL(root->right) &&
           isBST(root);
}

// ---------- Check Full Binary Tree ----------
bool isFullBinary(struct Node* root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;
    if (root->left && root->right)
        return isFullBinary(root->left) && isFullBinary(root->right);
    return false;
}

// ---------- Check Complete Binary Tree ----------
bool isCompleteBinary(struct Node* root) {
    if (root == NULL) return true;

    struct Node* queue[MAX];
    int front = 0, rear = 0;
    bool foundNull = false;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        if (current == NULL) {
            foundNull = true;
        } else {
            if (foundNull)
                return false;
            queue[rear++] = current->left;
            queue[rear++] = current->right;
        }
    }
    return true;
}

// ---------- Menu ----------
void menu() {
    printf("\n==== Tree Property Checker ====\n");
    printf("1. Insert node\n");
    printf("2. Check if BST\n");
    printf("3. Check if AVL Tree\n");
    printf("4. Check if Full Binary Tree\n");
    printf("5. Check if Complete Binary Tree\n");
    printf("0. Exit\n");
    printf("Enter choice: ");
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf(isBST(root) ? "Yes, it's a BST.\n" : "No, not a BST.\n");
            break;
        case 3:
            printf(isAVL(root) ? "Yes, it's an AVL Tree.\n" : "No, not an AVL Tree.\n");
            break;
        case 4:
            printf(isFullBinary(root) ? "Yes, it's a Full Binary Tree.\n" : "No, not a Full Binary Tree.\n");
            break;
        case 5:
            printf(isCompleteBinary(root) ? "Yes, it's a Complete Binary Tree.\n" : "No, not a Complete Binary Tree.\n");
            break;
        case 0:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
