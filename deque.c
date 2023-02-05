#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node* next;
	struct Node* prev;
}Node;

typedef struct Deque {
	int size;
	struct Node* back;
	struct Node* front;
}Deque;

Deque* newDeque() {
	Deque* que;
	que = (Deque*)malloc(sizeof(Deque));
	que->size = 0;
	que->front = NULL;
	que->back = NULL;

	return que;
}

void pushFront(Deque* que, int val) {
	Node* selectNode = que->front;
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->value = val;
	newNode->prev = NULL;
	if (que->front == NULL) {
		que->front = newNode;
		que->back = newNode;
	}
	else {
		newNode->next = selectNode;
		selectNode->prev = newNode;
		que->front = newNode;

		/*while (selectNode->next != NULL)
			selectNode = selectNode->next;*/
	}
	que->size++;
}

void pushBack(Deque* que, int val) {
	Node* selectNode = que->back;
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->value = val;
	newNode->next = NULL;
	if (que->back == NULL) {
		que->back = newNode;
		que->front = newNode;
	}
	else {
		newNode->prev = selectNode;
		selectNode->next = newNode;
		que->back = newNode;

		/*while (selectNode->next != NULL)
			selectNode = selectNode->next;*/
	}
	que->size++;
}

void popFront(Deque* que) {
	Node* selectNode = que->front;
	if (que->size > 1) {
		selectNode = selectNode->next;
		free(que->front);
		que->front = selectNode;
		selectNode->prev = NULL;
	}
	else {
		free(que->front);
		que->front = NULL;
	}
	que->size--;
}

void popBack(Deque* que) {
	Node* selectNode = que->back;
	if (que->size > 1) {
		selectNode = selectNode->prev;
		free(que->back);
		que->back = selectNode;
		selectNode->next = NULL;
	}
	else {
		free(que->back);
		que->back = NULL;
	}
	que->size--;
}

void show(Deque* que) {
	Node* selectNode = que->front;
	printf("size: %d\n", que->size);
	printf("value: ");
	do {
		printf("%d ", selectNode->value);
		selectNode = selectNode->next;
	} while (selectNode != NULL);
	printf("\n");
}