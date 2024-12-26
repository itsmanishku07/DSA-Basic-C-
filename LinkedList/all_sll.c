#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *start = NULL;

void insertAtBeg()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data: ");
    scanf("%d", &new_node->data);

    new_node->next = NULL;

    if (start == NULL)
    {
        start = new_node;
    }
    else
    {
        new_node->next = start;
        start = new_node;
    }
}

void insertAtEnd()
{
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data: ");
    scanf("%d", &new_node->data);

    new_node->next = NULL;

    if (start == NULL)
    {
        start = new_node;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insertBeforeSpecificElement(int n)
{
    struct node *new_node, *temp, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (start->data == n)
    {
        new_node->next = start;
        start = new_node;
    }
    else
    {
        temp = start;
        while (temp->data != n)
        {
            ptr = temp;
            temp = temp->next;
        }
        new_node->next = temp;
        ptr->next = new_node;
    }
}

void deleteSpecificNode(int n)
{
    struct node *temp, *ptr;

    if (start->data == n)
    {
        temp = start;
        start = temp->next;
        free(temp);
    }
    else
    {
        temp = start;
        while (temp->data != n)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = temp->next;
        free(temp);
    }
}

void deleteAllNodes()
{
    struct node *temp, *ptr;
    temp = start;

    while (temp->next != NULL)
    {
        ptr = temp->next;
        free(temp);
        temp = ptr;
    }
    start = NULL;
}

void display()
{
    if (start == NULL)
    {
        printf("No Element Is There In Linked List.....");
    }
    else
    {

        printf("\nList is:\n ");
        struct node *temp;
        temp = start;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void main()
{
    int c;
    // int n;
    // insertAtBeg();
    // insertAtBeg();
    // insertAtBeg();
    // insertAtEnd();
    // insertAtEnd();
    // insertAtEnd();
    // display();
    // printf("Enter Data Before You Wanna Insert: ");
    // scanf("%d", &n);
    // insertBeforeSpecificElement(n);
    // display();
    // printf("Enter Data That You Wanna Delete: ");
    // scanf("%d",&n);
    // deleteSpecificNode(n);
    // display();
    do
    {

        int ch;
        printf("\n");
        printf("Press 1 For Insert At Beg\nPress 2 For Insert At End\nPress 3 For Insert Before Specific Element\nPress 4 For Delete Specific Element\nPress 5 For Display List\nPress 6 For Delete All Nodes\n\nOption: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            insertAtBeg();
            break;
        }
        case 2:
        {
            insertAtEnd();
            break;
        }
        case 3:
        {
            display();
            int c;
            printf("Enter Data Before You Wanna Insert: ");
            scanf("%d", &c);
            insertBeforeSpecificElement(c);
            display();
            break;
        }
        case 4:
        {
            display();
            int c;
            printf("Enter Element That You Wanna Delete: ");
            scanf("%d", &c);
            deleteSpecificNode(c);
            display();
            break;
        }
        case 5:
        {
            display();
            break;
        }
        case 6:
        {
            deleteAllNodes();
            break;
        }
        default:
        {
            printf("Invalid Input\n");
        }
        }
        printf("\n");
        printf("Continue..? Press 0 Else 1: ");
        scanf("%d", &c);

    } while (c != 1);
}