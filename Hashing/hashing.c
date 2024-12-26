#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    char name[100];
    struct Node *next;
} Node;

Node *hashTable[TABLE_SIZE];

int hashFunction(char *key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

void insertIntoHashTable(char *name) {
    int index = hashFunction(name);
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int searchInHashTable(char *name) {
    int index = hashFunction(name);
    Node *current = hashTable[index];
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return 1; 
        }
        current = current->next;
    }
    return 0; 
}

int linearSearch(char arr[][100], int size, char *target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], target) == 0) {
            return i;
        }
    }
    return -1;
}
int binarySearch(char arr[][100], int size, char *target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(arr[mid], target);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    printf("=== Hashing ===\n");
    char *names[] = {"John", "Alice", "Bob", "Eve", "Charlie"};
    int n = 5;

    for (int i = 0; i < n; i++) {
        insertIntoHashTable(names[i]);
    }

    char searchName[100];
    printf("Enter name to search in hash table: ");
    scanf("%s", searchName);

    if (searchInHashTable(searchName)) {
        printf("Found %s in hash table.\n", searchName);
    } else {
        printf("%s not found in hash table.\n", searchName);
    }

    printf("\n=== Searching ===\n");
    char unsortedNames[][100] = {"John", "Alice", "Bob", "Eve", "Charlie"};
    char sortedNames[][100] = {"Alice", "Bob", "Charlie", "Eve", "John"};

    printf("Enter name to search (linear search): ");
    scanf("%s", searchName);
    int linearResult = linearSearch(unsortedNames, n, searchName);
    if (linearResult != -1) {
        printf("Found %s at index %d (linear search).\n", searchName, linearResult);
    } else {
        printf("%s not found (linear search).\n", searchName);
    }

    printf("Enter name to search (binary search): ");
    scanf("%s", searchName);
    int binaryResult = binarySearch(sortedNames, n, searchName);
    if (binaryResult != -1) {
        printf("Found %s at index %d (binary search).\n", searchName, binaryResult);
    } else {
        printf("%s not found (binary search).\n", searchName);
    }

    return 0;
}
