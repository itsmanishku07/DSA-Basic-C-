#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

int height(Node *node)
{
    return node ? node->height : 0;
}

int getBalanceFactor(Node *node)
{
    return node ? height(node->left) - height(node->right) : 0;
}

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

Node *insert(Node *node, int data)
{
    if (!node)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void printTree(Node *root, int space)
{
    int COUNT = 10;
    if (!root)
        return;

    space += COUNT;

    printTree(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    printTree(root->left, space);
}

void inOrder(Node *root)
{
    printf("\n");
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d -> ", root->data);
        inOrder(root->right);
    }
    printf("\n");
}

int main()
{
    int data;
    Node *root = NULL;

    while (1)
    {
        int ch;
        printf("\n");
        printf("Press 1 For Enter Data\nPress 2 For InOrder Traversal\nPress 3 For Print Tree\nPress 4 For Exit\n\nOption: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            printf("Enter Datxa: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        }
        case 2:
            printf("InOrder Traversal:\n ");
            inOrder(root);
            break;
        case 3:
            printf("Tree Structure is: \n");
            printTree(root, 0);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Invalid Input.....");
        }
    }

    return 0;
}
