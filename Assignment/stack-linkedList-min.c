#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL;

int isEmpty()
{
    return top == NULL;
}

void push()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &new_node->data);

    new_node->next = NULL;
    new_node->next = top;
    top = new_node;
}

void pop()
{
    printf("\n");
    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Stack is Empty...");
    }
    else
    {
        printf("Pop: %d\n", temp->data);
        top = temp->next;
        free(temp);
    }
    printf("\n");
}
void display()
{
    printf("\n");
    if (top == NULL)
    {
        printf("Stack Is Empty....");
    }
    else
    {
        struct node *temp;
        temp = top;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

int minElement()
{
    struct node *temp;
    int min = top->data;
    temp = top;
    while(temp != NULL)
    {
        if(temp->data < min)
        {
            min = temp->data;
        }
        temp = temp->next;
    }
    return min;
}

void main()
{
    push();
    push();
    push();
    push();
    push();
    display();
    printf("Min Value is: %d", minElement());
}