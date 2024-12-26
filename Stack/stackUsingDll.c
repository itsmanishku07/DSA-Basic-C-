#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
} *top = NULL;

int isEmpty() {
    return top == NULL;
}

void push() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &new_node->data);

    new_node->next = top;
    new_node->prev = NULL;

    if (top != NULL) {
        top->prev = new_node;
    }
    top = new_node;
}

void pop() {
    printf("\n");
    if (top == NULL) {
        printf("Stack is Empty...\n");
    } else {
        struct node *temp = top;
        printf("Pop: %d\n", temp->data);
        
        top = temp->next;
        if (top != NULL) {
            top->prev = NULL;
        }
        free(temp);
    }
    printf("\n");
}

void peek() {
    printf("\n");
    if (top == NULL) {
        printf("Stack Is Empty...\n");
    } else {
        printf("Peek Element: %d\n", top->data);
    }
    printf("\n");
}

void display() {
    printf("\n");
    if (top == NULL) {
        printf("Stack Is Empty...\n");
    } else {
        struct node *temp = top;
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    while (1) {
        printf("\n");
        int c;
        printf("Press 1 For Push\nPress 2 For Pop \nPress 3 For Display \nPress 4 For Peek\nPress 5 For Exit\nOption: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Input\n");
        }
    }
    return 0;
}