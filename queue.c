#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node* next;
}Node;

typedef struct Queue {
	int size;
	struct Node* back;
	struct Node* front;
}Queue;

Queue* newQueue() {
	Queue* que;
	que = (Queue*)malloc(sizeof(Queue));
	que->size = 0;
	que->front = NULL;
	que->back = NULL;

	return que;
}

void push(Queue* que, int val) {
	Node* selectNode = que->back;
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->value = val;
	newNode->next = NULL;
	if (que->front == NULL) {
		que->front = newNode;
		que->back = newNode;
	}
	else {
		selectNode->next = newNode;
		que->back = newNode;

		/*while (selectNode->next != NULL)
			selectNode = selectNode->next;*/
	}
	que->size++;
}

void pop(Queue* que) {
	Node* selectNode = que->front;
	if (que->size > 1) {
		selectNode = selectNode->next;
		free(que->front);
		que->front = selectNode;
	}
	else {
		free(que->front);
		que->front = NULL;
	}
	que->size--;
}

void show(Queue* que) {
	Node* selectNode = que->front;
	printf("size: %d\n", que->size);
	printf("value: ");
	do {
		printf("%d ", selectNode->value);
		selectNode = selectNode->next;
	} while (selectNode != NULL);
	printf("\n");
}