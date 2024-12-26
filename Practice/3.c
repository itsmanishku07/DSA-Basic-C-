#include <stdio.h>

void main()
{
    int rows = 26;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%c ", 'A' + j);
        }
        printf("\n");
    }


    // for(int i = 0; i < 26; i++)
    // {
    //     printf("%c\n",'a' + i);
    // }
}