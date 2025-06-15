int search(struct Node* root, int key) {
    if (root == NULL)
        return 0;
    if (root->key == key)
        return 1;
    else if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);

    printf("Search 10: %s\n", search(root, 10) ? "Found" : "Not Found");
    printf("Search 25: %s\n", search(root, 25) ? "Found" : "Not Found");
    return 0;
}
