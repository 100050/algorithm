#include <stdio.h>

void swap(int* d1, int* d2);

int main() {
	int i, j, n, s;
	int d[100];
	s = 0;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) { // �� �Է� 
		scanf("%d", &d[i]);
	}
	while (1) {
		for (i = 1; i<n; i++) {
			if (d[i-1] > d[i]) { // �տ� ���� ũ�ٸ� 
				swap(&d[i-1], &d[i]); // ���� �� ���� 
			} 
			else { // �ƴ϶�� 
				break; // �ݺ��� �� 
			}
		}
		for(j = 1; j<n; j++) { 
			if (d[j-1] < d[j]) {
				s++;
			}
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
