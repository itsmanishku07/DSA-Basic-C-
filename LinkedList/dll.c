#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *start = NULL;

int getNodeCount()
{
    struct node *temp;
    temp = start;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
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

void insertAtBeg()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data: ");
    scanf("%d", &new_node->data);
    // new_node->data = n;

    new_node->prev = NULL;
    new_node->next = NULL;

    if (start == NULL)
    {
        start = new_node;
    }
    else
    {
        start->prev = new_node;
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

void insertbeforeElement()
{
    printf("\n");
    display();
    printf("\n");

    int e;
    printf("Enter Data Before You Wanna Insert: ");
    scanf("%d", &e);

    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data: ");
    scanf("%d", &new_node->data);

    new_node->next = NULL;
    new_node->prev = NULL;

    if (start->data == e)
    {
        start->prev = new_node;
        new_node->next = start;
        start = new_node;
    }
    else
    {
        temp = start;
        while (temp->data != e)
        {
            temp = temp->next;
        }
        new_node->next = temp;
        new_node->prev = temp->prev;
        temp->prev->next = new_node;
    }
}

void insertByIndex()
{
    struct node *new_node;
    int index;
    new_node = (struct node *)malloc(sizeof(struct node));
    display();
    printf("Enter Index: ");
    scanf("%d", &index);

    if (index > getNodeCount())
    {
        printf("Index Not Found");
    }
    else
    {

        int count = 0;
        printf("Enter Data: ");
        scanf("%d", &new_node->data);
        if (index == 0)
        {
            start->prev = new_node;
            new_node->next = start;
            start = new_node;
        }
        else
        {
            struct node *temp;
            temp = start;
            while (index != count)
            {
                count++;
                temp = temp->next;
            }
            new_node->next = temp;
            new_node->prev = temp->prev;
            temp->prev->next = new_node;
            temp->prev = new_node;
        }
    }
}

void deleteSpecificNode()
{
    int e;
    printf("Enter Data that You wanna Delete: ");
    scanf("%d", &e);
    struct node *temp;

    if (start->data == e)
    {
        temp = start;
        // temp->next = start;
        start = temp->next;
        free(temp);
    }
    else
    {
        temp = start;
        while (temp->data != e)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    display();
}

void removeDuplicates()
{
    struct node *current = start;

    while (current != NULL)
    {
        struct node *currentNext = current->next;

        while (currentNext != NULL)
        {
            if (currentNext->data == current->data)
            {
                struct node *temp = currentNext;

                if (currentNext->next != NULL)
                {
                    currentNext->next->prev = currentNext->prev;
                }
                currentNext->prev->next = currentNext->next;

                currentNext = currentNext->next;
                free(temp);
            }
            else
            {
                currentNext = currentNext->next;
            }
        }

        current = current->next;
    }
}

void main()
{
    int c;
    do
    {

        int ch;
        printf("\n");
        printf("Press 1 For Insert At Beg\nPress 2 For Insert At End\nPress 3 For Insert Before Specific Element\nPress 4 For Insert Into Given Index\nPress 5 For Delete Specific Element\nPress 6 For Display List\nPress 7 For Exit\n\nOption: ");
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
            insertbeforeElement();
            break;
        }
        case 4:
        {
            insertByIndex();
            break;
        }
        case 5:
        {
            display();
            deleteSpecificNode();
            display();
            break;
        }
        case 6:
        {
            display();
            break;
        }
        case 7:
        {
            exit(0);
        }
        case 8:
        {
            removeDuplicates();
            break;
        }
        default:
        {
            printf("Invalid Input\n");
        }
        }

    } while (1);
}
