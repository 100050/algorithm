#include <stdio.h>

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// 버블정렬
void bubbleSort(int arr[], int n) {
	int i, j;
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-1; j++) {
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

// 선택정렬
void selectionSort(int arr[], int n) {
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

// 삽입정렬
void insertionSort(int arr[], int n) {
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

// 병합정렬
void mergeSort(int arr[], int n) {

}

// 퀵정렬
void quickSort(int arr[], int L, int R) {
	int pivot;
	int left, right;
	left = L;
	right = R;
	pivot = arr[(L + R) / 2];

	do {
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;

		if (left <= right) {
			swap(&arr[right], &arr[left]);
			right--;
			left++;
		}

	} while (left <= right);

	if (L < right)
		quickSort(arr, L, right);

	if (left < R)
		quickSort(arr, left, R);
}

int main() {
	int i;
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1};
	quickSort(arr, 0, 9);
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}