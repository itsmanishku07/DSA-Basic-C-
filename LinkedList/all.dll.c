#include <stdio.h>
#include <stdlib.h>

int flag = 0;
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

void isDublicate(int n)
{
    if (start != NULL)
    {
        struct node *temp;
        temp = start;
        while (temp != NULL)
        {
            if (temp->data == n)
            {
                // printf("Data Already Exist");
                flag = 1;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
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

    isDublicate(new_node->data);

    if (flag == 0)
    {
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
    else
    {
        printf("\nData Already Exist....\n");
        flag = 0;
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
    isDublicate(new_node->data);
    if (flag == 0)
    {

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
    else
    {
        printf("Data Already Exist...");
        flag = 0;
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

    isDublicate(new_node->data);
    if (flag == 0)
    {

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
    else
    {
        printf("Data Already Exist...");
        flag = 0;
    }
}

void removeDuplicates() {
    struct node* current = start;
    
    while (current != NULL) {
        struct node* currentNext = current->next;
        
        while (currentNext != NULL) {
            if (currentNext->data == current->data) {
                struct node* temp = currentNext;
                
                if (currentNext->next != NULL) {
                    currentNext->next->prev = currentNext->prev;
                }
                currentNext->prev->next = currentNext->next;
                
                currentNext = currentNext->next;
                free(temp);
            } else {
                currentNext = currentNext->next;
            }
        }
        
        current = current->next;
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

void insertWithoutDublicateAtBeg()
{
    struct node *new_node, *temp;
    int data, flag = 0;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &data);
    new_node->data = data;
    new_node->next = NULL;
    temp = start;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Data Already Exist.....");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        insertAtBeg(data);

        // start->prev = new_node;
        // new_node->next = start;
        // start = new_node;
    }
}

void main()
{
    int c;
    do
    {

        int ch;
        printf("\n");
        printf("Press 1 For Insert At Beg\nPress 2 For Insert At End\nPress 3 For Insert Before Specific Element\nPress 4 For Delete Specific Element\nPress 5 For Display List\n\n\nOption: ");
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
            display();
            deleteSpecificNode();
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
            exit(0);
        }
        case 7:
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
