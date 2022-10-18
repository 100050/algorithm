#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[10000];
int top = -1;

// 가장 위 원소 삭제
void pop() {
	if (top >= 0) {
		printf("delate %d\n", stack[top]);
		stack[top--] = 0;
	}
	else
		printf("null\n");
}

// 원소 삽입
void push(int data) {
	stack[++top] = data;
	printf("%d\n", stack[top]);
}


// 가장 위의 원소
void isTop() {
	if (top == -1)
		printf("null\n");
	else
		printf("%d\n", stack[top]);
}

// 스택이 비었는가
void isEmpty() {
	if (top == -1)
		printf("yes\n");
	else
		printf("no\n");
}

// 원소 갯수
void isSize() {
	printf("%d\n", top + 1);
}

void show() {
	int i;
	printf("{ ");
	for (i = 0; i < top + 1; i++) {
		printf("%d ", stack[i]);
	}
	printf("}\n");
}

int main() {
	char answer[11];
	int data;
	while (1) {
		scanf("%s", answer);
		if (strcmp(answer, "push") == 0) {
			scanf("%d", &data);
			push(data);
		}
		else if (strcmp(answer, "top") == 0) {
			isTop();
		}
		else if (strcmp(answer, "pop") == 0) {
			pop();
		}
		else if (strcmp(answer, "show") == 0) {
			show();
		}
		else if (strcmp(answer, "size") == 0) {
			isSize();
		}
		else if (strcmp(answer, "empty") == 0) {
			isEmpty();
		}
		else if (strcmp(answer, "stop") == 0) {
			break;
		}
	}

	return 0;
}