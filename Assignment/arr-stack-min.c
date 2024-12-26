#include<stdio.h>

int stack[5];
int top = -1;



void push()
{
    int item;
    if(top == 4)
    {
        printf("Stack Is Full..");
    }
    else
    {
        printf("Enter The Element To Be Inserted: ");
        scanf("%d",&item);
        top = top + 1;
        stack[top] = item;
    }
}

void pop()
{
    int item;
    if(top == -1)
    {
        printf("Stack Is Empty...");
    }
    else
    {
        item = stack[top];
        top = top - 1;
    }
    printf("Pop Item is: %d",item);
    printf("\n");
}

void display()
{
    if(top == -1)
    {
        printf("Stack is Empty...");
    }
    else
    {
        printf("Your Elements is: \n");
        for(int i = top; i >= 0; i--)
        {
            printf("%d\t",stack[i]);
        }
    }
    printf("\n");
}

void minElement()
{
    int min = stack[0];
    if(top == -1)
    {
        printf("Stack is Empty...");
    }
    else
    {
        for(int i = top; i >= 0; i--)
        {
            if(stack[i] < min)
            {
                min = stack[i];
            }
        }
    }
    printf("The Min Element of Stack is: %d", min);
    printf("\n");
}


void main()
{
    push();
    push();
    push();
    push();
    push();
    display();
    minElement();
}