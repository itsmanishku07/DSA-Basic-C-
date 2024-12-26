#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *start = NULL;

void display()
{
    printf("\n");
    struct node *temp;
    temp = start;

    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtEnd()
{
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data: ");
    scanf("%d", &new_node->data);

    new_node->prev = NULL;
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
        new_node->prev = temp;
    }
}


void evenOdd(struct node *start)
{
    struct node *i, *j;
    int num, temp;
    for (i = start; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data % 2 != 0)
            {
                temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
        }
    }
}

void main()
{
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    display();
    evenOdd(start);
    display();
}