#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data); 
    }

    if (data < root->data) {
        root->left = insert(root->left, data); 
    } else if (data > root->data) {
        root->right = insert(root->right, data); 
    }

    return root; 
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }


    if (key > root->data) {
        return search(root->right, key);
    }

    return search(root->left, key);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal of BST: ");
    inorder(root);
    printf("\n");

    int key = 40;
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("Found the value %d in the BST.\n", key);
    } else {
        printf("Value %d not found in the BST.\n", key);
    }
}
