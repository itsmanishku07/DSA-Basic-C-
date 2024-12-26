#include <stdio.h>
#include <stdlib.h>

struct sparse
{
    int row;
    int column;
    int value;
    struct sparse *next;
} *start = NULL;

void insertAtEnd(struct sparse *head, int row, int column, int value)
{
    struct sparse *new_node, *temp;
    new_node = (struct sparse *)malloc(sizeof(struct sparse));

    new_node->row = row;
    new_node->column = column;
    new_node->value = value;

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

void takeInput(int r, int c, int arr[r][c])
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("Index[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
}

int checkSparse(int r, int c, int arr[r][c])
{
    int zeroEle = 0, nonZeroEle = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 0)
            {
                zeroEle++;
            }
            else
            {
                nonZeroEle++;
            }
        }
    }

    return zeroEle > nonZeroEle;
}

void displaySparseMatrix()
{
    struct sparse *temp = start;
    while (temp != NULL)
    {
        printf("Row: %d Column: %d Value: %d\n", temp->row, temp->column, temp->value);
        temp = temp->next;
    }
}

void doIt(int r, int c, int arr[r][c])
{
    if (checkSparse(r,c,arr))
    {

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (arr[i][j] != 0)
                {
                    insertAtEnd(start, i, j, arr[i][j]);
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("\n");
        printf("Sorry! :( Given Matrix is Not Sparse matrix.............");
    }
}

void main()
{
    int r,c;
    printf("Enter Row: ");
    scanf("%d",&r);
    printf("Enter Column: ");
    scanf("%d",&c);
    int arr[r][c];
    takeInput(r,c,arr);
    doIt(r,c,arr);
    displaySparseMatrix();
}
