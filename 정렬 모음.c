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
int arr2[10];
void merge(int arr[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid+1;
	k = left;
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			arr2[k++] = arr[i++];
		else
			arr2[k++] = arr[j++];
	}

	if (i > mid) {
		for (l = j; l <= right; l++)
			arr2[k++] = arr[l];
	}
	else {
		for (l = i; l <= mid; l++)
			arr2[k++] = arr[l];
	}

	for (i = left; i <= right; i++) {
		arr[i] = arr2[i];
	}
}

void mergeSort(int arr[], int left, int right) {
	int mid;
	if (left<right) {
		mid = (right + left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
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

// 힙정렬
void heepSort() {

}

// 기수정렬
void radixSort() {

}

int main() {
	int i;
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1};
	mergeSort(arr, 0, 9);
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}