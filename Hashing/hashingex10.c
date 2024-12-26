#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *hashTable[TABLE_SIZE];

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insert(int key)
{
    int index = hashFunction(key);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    printf("Inserted %d at index %d\n", key, index);
}

int search(int key)
{
    int index = hashFunction(key);
    Node *current = hashTable[index];

    while (current != NULL)
    {
        if (current->data == key)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Index %d: ", i);
        Node *current = hashTable[i];
        while (current != NULL)
        {
            printf("%d -> ", current->data);
            current = current->next; // Move to next node
        }
        printf("NULL\n");
    }
}

int main()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = NULL;
    }
    int ch;
    while (1)
    {
        printf("\n");
        printf("Press 1 For Insert\nPress 2 For Search Key\nPress 3 For Display\nPress 4 For Exit\n\nOption: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            int data;
            printf("Enter Data: ");
            scanf("%d", &data);
            insert(data);
            break;
        }
        case 2:
        {
            int i;
            printf("Enter Key For Search: ");
            scanf("%d", &i);
            if (search(i))
                printf("\nElement %d found in the hash table.\n", i);
            else
                printf("\nElement %d not found in the hash table.\n", i);
            break;
        }
        case 3:
            printf("\nHash Table \n");
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Invalid Input...");
        }
    }

    
}