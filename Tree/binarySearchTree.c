#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
} *root = NULL;

struct Node *createNode(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insertNode(struct Node *node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);

    return node;
}

void inOrder(struct Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct Node *searchNode(struct Node *root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data > root->data)
        return searchNode(root->right, data);

    return searchNode(root->left, data);
}

void printSpaces(int level) {
    for (int i = 0; i < level; i++) {
        printf("    "); 
    }
}

void printTree(struct Node *root, int level) {
    if (root == NULL) {
        return;
    }

    printTree(root->right, level + 1);

    printSpaces(level);
    printf("%d\n", root->data);

    printTree(root->left, level + 1);
}


int main() {
    int ch;
    while (1) {
        printf("\nPress 1: Insert Node\nPress 2: In-Order Traversal\nPress 3: Search Node\nPress 4: for Print Tree\nPress 5: Exit\n\nOption: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                int data;
                printf("Enter Data: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            }
            case 2: {
                printf("In-Order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            }
            case 3: {
                int n;
                printf("Enter Data to Search: ");
                scanf("%d", &n);
                struct Node *result = searchNode(root, n);
                if (result != NULL)
                    printf("Element %d is present in the BST\n", n);
                else
                    printf("Element %d is not present in the BST\n", n);
                break;
            }
            case 4:
                printTree(root,0);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Input...\n");
                break;
        }
    }
    return 0;
}
