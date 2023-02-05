#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node* next;
}Node;

typedef struct LinkedList {
	int size;
	struct Node* head;
}List;

List* newList() {
	List* list;
	list = (List*)malloc(sizeof(List));
	list->size = 0;
	list->head = NULL;

	return list;
}

void insert(List* list, int val, int isBack) {
	Node* selectNode = list->head;
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->value = val;
	newNode->next = NULL;
	if (list->head == NULL)
		list->head = newNode;
	else {
		if (isBack == 1) {
			while (selectNode->next != NULL)
				selectNode = selectNode->next;

			selectNode->next = newNode;
		}
		else if (isBack == 0) { // front
			list->head = newNode;
			newNode->next = selectNode;
		}
	}
	list->size++;
}

void del(List* list, int isBack) {
	Node* selectNode = list->head;
	if (list->size > 1) {
		if (isBack == 1) {
			for (int i = 0; i < list->size - 2; i++) {
				selectNode = selectNode->next;
			}
			free(selectNode->next);
			selectNode->next = NULL;
		}
		else if (isBack == 0) { //front
			selectNode = selectNode->next;
			free(list->head);
			list->head = selectNode;
		}
	}
	else {
		free(list->head);
		list->head = NULL;
	}
	list->size--;
}

void show(List* list) {
	Node* selectNode = list->head;
	printf("size: %d\n", list->size);
	printf("value: ");
	do {
		printf("%d ", selectNode->value);
		selectNode = selectNode->next;
	} while (selectNode != NULL);
	printf("\n");
}