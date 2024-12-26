#include<stdio.h>
#include<conio.h>

void main()
{
    int arr[3][3], arr1[3][3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arr[i][j] = i;
            arr1[i][j] = j;
        }
    }

    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d\t",arr1[i][j]);
        }
        printf("\n");
    }
    
}