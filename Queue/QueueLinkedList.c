#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
}*start = NULL;

struct node *createNode() {
	struct node *newNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	printf("Enter Data: ");
	scanf("%d", &newNode->data);
	newNode->next = NULL;
	return newNode;
}

void enQueue() {
	struct node *newNode = createNode();
	if(start == NULL) {
		start = newNode;
	} else {
		struct node *temp = start;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
	printf("Data Inserted\n");
}

void deQueue() {
	if(start == NULL) {
		printf("Queue is Empty...\n");
	} else {
		struct node *temp = start;
		printf("Dequeued Element: %d\n", temp->data);
		start = start->next;
		free(temp); 
	}
}

void displayQueue() {
	if(start == NULL) {
		printf("Queue is Empty...\n");
	} else {
		struct node *temp = start;
		printf("Queue is:\n");
		while(temp != NULL) {
			printf("%d\t", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

void main() {
	int ch;
	while(1) {
		printf("\n");
		printf("Press 1 For EnQueue\nPress 2 For DeQueue\nPress 3 For Display\nPress 4 For Exit\n\nOption: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				enQueue();
				break;
			case 2:
				deQueue();
				break;
			case 3:
				displayQueue();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid Input...\n");
				break;
		}
	}
}
