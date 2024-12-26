#include<stdio.h>
#include<stdlib.h>

int *row;
int *column;
int *value;
int nonZero;

int checkSparse(int r, int c, int arr[r][c])
{
    int zeroEle = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(arr[i][j] == 0)
            {
                zeroEle++;
            }
            else
            {
                nonZero++;
            }

        }
    return zeroEle > nonZero;
    }
}


void sparseMatrix(int r, int c, int v)
{
    int i = 0;
    row = (int *)malloc(sizeof(int));
    column = (int *)malloc(sizeof(int));
    value = (int *)malloc(sizeof(int));

    row[i] = r;
    column[i] = c;
    value[i] = v;
    i++;
}

void printList(int r, int c, int arr[r][c])
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(arr[i][j] != 0)
            {
                sparseMatrix(i,j,arr[i][j]);
            }
        }
    }
}

void display(int r, int c)
{
    for(int i = 0; i < nonZero; i++)
    {
        printf("Row: %d Column: %d Value: %d\n", row[i], column[i], value[i]);
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

void main()
{
    int r,c;
    printf("Enter Row: ");
    scanf("%d",&r);
    printf("Enter Column: ");
    scanf("%d",&c);
    int arr[r][c];
    takeInput(r,c,arr);
    printList(r,c,arr);   
    display(r,c);
}