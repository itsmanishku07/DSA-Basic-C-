#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
}*start = NULL;

void display()
{
    printf("\n");
    struct node *temp;
    temp = start;

    do
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }while(temp != start);
    printf("\n");
}

// void insertAtBeg()
// {
//     struct node *new_node;
//     new_node = (struct node *)malloc(sizeof(struct node));
//     printf("Enter Data: ");
//     scanf("%d",&new_node->data);
//     if(start == NULL)
//     {
//         start = new_node;
//         new_node->next = start;
//     }
//     else
//     {
//         new_node->next = start;
//         start->next = new_node;
//         start = new_node;
//     }
// }

void insertAtBeg()
{
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&new_node -> data);
    
    if (start == NULL)
    {
        start = new_node;
        new_node -> next = start;
    }
    else
    {
        temp = start;
        while (temp -> next != start)
        {
            temp = temp -> next;
        }
        new_node -> next = start;
        temp -> next = new_node;
        start = new_node; 
    }
}

void insertAtEnd()
{
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&new_node -> data);

    if(start == NULL)
    {
        start = new_node;
        new_node->next = start;
    }
    else
    {
        temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}
void main()
{
    // insertAtBeg();
    // insertAtBeg();
    // insertAtBeg();
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    display();
}