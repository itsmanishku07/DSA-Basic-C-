#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *start1 = NULL, *start2 = NULL;

void insertFirstList()
{
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data: ");
    scanf("%d", &new_node->data);

    new_node->prev = NULL;
    new_node->next = NULL;
    if (start1 == NULL)
    {
        start1 = new_node;
    }
    else
    {
        temp = start1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void insertSecondList()
{
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data: ");
    scanf("%d", &new_node->data);

    new_node->prev = NULL;
    new_node->next = NULL;
    if (start2 == NULL)
    {
        start2 = new_node;
    }
    else
    {
        temp = start2;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void display(struct node *start)
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

// void margeList(struct node *list1, struct node *list2)
// {
//     while (list1 != NULL)
//     {
//         list1 = list1->next;
//     }
//     while (list2 != NULL)
//     {
//         list1->next = list2;
//         list2 = list2->next;
//     }
//     display(list1);
// }

struct node *mergeLists(struct node *head1, struct node *head2)
{

    struct node *temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head2;
    head2->prev = temp;

    return head1;
}

void sort(struct node *start)
{
    struct node *i, *j;
    int num, temp;
    for (i = start; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
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
    struct node *new_node;
    insertFirstList();
    insertFirstList();
    insertFirstList();
    insertSecondList();
    insertSecondList();
    insertSecondList();

    struct node *start3 = mergeLists(start1, start2);
    display(start3);
    sort(start3);
    display(start3);
}