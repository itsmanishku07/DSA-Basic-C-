#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
} *start = NULL;
int count = 0;
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
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    printf("%d",getElementCount());  
    display();
}
