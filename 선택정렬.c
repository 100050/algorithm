#include <stdio.h>

void swap(int* d1, int* d2);

int main() {
	int i, j, n, s;
	int* min;
	int d[100];
	s = 0;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) { // 값 입력 기 
		scanf("%d", &d[i]);
	}
	
	while (1) {
		for (j = 0; j < n; j++) {
			min = &d[j];
			for (i = j+1; i < n; i++) {
				if (*min > d[i]) { // 제일 작은 값 찾기 
					min = &d[i]; 
				}
			}
			swap(min, &d[j]); // 작은 값과 j번째와 위치 바꾸 
			s++;
		}
		if (s == n) break;
	}
	
	for (i = 0; i < n; i++) { // 값 출력 
		printf("%d ", d[i]);
	}
	
	return 0;
}

void swap(int* d1, int* d2) { 
	int a;
	a = *d1;
	*d1 = *d2;
	*d2 = a;
}
