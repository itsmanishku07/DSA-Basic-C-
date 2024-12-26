#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

void peek()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
        {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

void main()
{
    int ch;
    while (1)
    {
        printf("Press 1 For EnQueue\nPress 2 For DeQueue\nPress 3 For Peek\nPress 4 For Display\nPress 5 For Exit\n\nOption: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            int n;
            printf("Enter Data: ");
            scanf("%d", &n);
            enqueue(n);
            break;
        }
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("Invalid Input.....");
        }
    }
}
