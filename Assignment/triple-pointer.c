#include<stdio.h>
#include<stdlib.h>

void updateValue(int ***ptr)
{
    int val;
    printf("Enter New Value: ");
    scanf("%d",&val);
    ***ptr = val;
}
void main()
{
    int n = 101;
    int ***ptr1, **ptr2, *ptr3;
    ptr3 = &n;
    ptr2 = &ptr3;
    ptr1 = &ptr2;
    printf("%d\n",(***(ptr1)));
    updateValue(ptr1);
    printf("%d\n",(***(ptr1)));
}