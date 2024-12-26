#define size 20
#include <stdio.h>
#include <stdlib.h>

int queue[size];
int front = -1, rear = -1;

void enQueue()
{
    if (rear == size - 1)
    {
        printf("Queue is Full...\n");
    }
    else
    {
        int data;
        printf("Enter Data: ");
        scanf("%d", &data);
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("Data Inserted\n");
    }
}

void deQueue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty...\n");
    }
    else
    {
        printf("Dequeue Element is: %d\n", queue[front]);
        front++;
        if (front > rear)
        { 
            front = rear = -1;
        }
    }
}

void displayQueue()
{
    if (front == -1)
    {
        printf("Queue is Empty...\n");
    }
    else
    {
        printf("Queue is:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}

void main()
{
    int ch;
    while (1)
    {
        printf("\n");
        printf("Press 1 For EnQueue\nPress 2 For DeQueue\nPress 3 For Display\nPress 4 For Exit\n\nOption: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enQueue();
            break;
        case 2:
            deQueue();
            break;
        case 3:
            displayQueue();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Input....\n");
            break;
        }
    }
}
