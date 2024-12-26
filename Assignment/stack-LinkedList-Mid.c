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
    if (top == NULL)
    {
        top = new_node;
    }
    else
    {
        // top->next = new_node;
        new_node->next = top;
        top = new_node;
    }
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

int midElement()
{
    int count = 0, mid, k = 0, ele;
    struct node *temp, *ptr;
    temp = top;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    mid = count / 2;
    ptr = top;
    if (count % 2 == 0)
    {
        while (k != mid)
        {
            ++k;
            ele = ptr->data;
            ptr = ptr->next;
        }
    }
    else
    {
        while (k != mid + 1)
        {
            ++k;
            ele = ptr->data;
            ptr = ptr->next;
        }
    }
    return ele;
}

void main()
{
    push();
    push();
    push();
    push();
    display();
    printf("%d", midElement());
    // midElement();
    // // pop();
}