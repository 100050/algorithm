#include <stdio.h>

void swap(int* d1, int* d2);

int main() {
	int i, j, n, s;
	int* min;
	int d[100];
	s = 0;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) { // �� �Է� �� 
		scanf("%d", &d[i]);
	}
	
	while (1) {
		for (j = 0; j < n; j++) {
			min = &d[j];
			for (i = j+1; i < n; i++) {
				if (*min > d[i]) { // ���� ���� �� ã�� 
					min = &d[i]; 
				}
			}
			swap(min, &d[j]); // ���� ���� j��°�� ��ġ �ٲ� 
			s++;
		}
		if (s == n) break;
	}
	
	for (i = 0; i < n; i++) { // �� ��� 
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
