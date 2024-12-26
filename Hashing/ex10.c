#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10 

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;  
}

void insert(int key) {
    int index = hashFunction(key);  
    Node* newNode = (Node*)malloc(sizeof(Node));  
        newNode->data = key;
    newNode->next = hashTable[index];    
      hashTable[index] = newNode;  
    printf("Inserted %d at index %d\n", key, index);
}

int search(int key) {
    int index = hashFunction(key); 
    Node* current = hashTable[index];  

    while (current != NULL) {
        if (current->data == key) {
            return 1;  
        }
        current = current->next;  
    }
    return 0;  
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* current = hashTable[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;  // Move to next node
        }
        printf("NULL\n");
    }
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }


    insert(15);
    insert(25);
    insert(35);
    insert(5);
    insert(11);
    insert(21);

    printf("\nHash Table after insertions:\n");
    display();

    int searchKey = 25;
    if (search(searchKey)) {
        printf("\nElement %d found in the hash table.\n", searchKey);
    } else {
        printf("\nElement %d not found in the hash table.\n", searchKey);
    }

    searchKey = 50;
    if (search(searchKey)) {
        printf("Element %d found in the hash table.\n", searchKey);
    } else {
        printf("Element %d not found in the hash table.\n", searchKey);
    }

    return 0;
}