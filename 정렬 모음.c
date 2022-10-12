#include <stdio.h>

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// ��������
void bubbleSort(int n, int* arr) {
	int i, j;
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-1; j++) {
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

// ��������
void selectionSort(int n, int* arr) {
	int i, j, min;
	for (i = 0; i < n; i++) {
		min = i;
		for (j = i; j < n; j++) {
			if (arr[min] > arr[j])
				min = j;
		}
		swap(&arr[min], &arr[i]);
	}
}

// ��������
void insertionSort(int n, int* arr) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (key < arr[j]) {
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j + 1] = key;
	}
}

// ��������
void mergeSort(int n, int* arr) {

}

// ������
void quickSort(int n, int* arr) {

}

int main_() {
	int i;
	int arr[10] = { 10,5,2,3,5,7,102,23,1,5 };
	bubbleSort(10, arr);
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}