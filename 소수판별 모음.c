#include <stdio.h>
#include <stdlib.h>

// �Ϲ����� ���
void isPrime(int n) {
	int i, cnt;
	cnt = 0;
	for (i = 1; i*i < n; i++) {
		if (n % i == 0)
			cnt++;
	}
	if (cnt == 1)
		printf("prime nuber");
	else
		printf("composition number");
}

// �����佺�׳׽��� ü�� �̿��� ���
void eratos(int n) {
	int i, j, cnt;
	int* arr;
	arr = (int*)malloc(sizeof(int) * (n+1));
	for (i = 1; i <= n; i++) {
		arr[i] = 1;
	}
	for (i = 2; i * i <= n; i++) {
		cnt = 0;
		if (arr[i] == 0)
			continue;
		for (j = 1; j * j <= i; j++) {
			if (i % j == 0)
				cnt++;
		}
		if (cnt == 1) {
			for (j = 2; i*j <= n; j++) {
				arr[i * j] = 0;
			}
		}
	}

	if (arr[n] == 1)
		printf("prime nuber");
	else
		printf("composition number");

	free(arr);
}

int main_() {
	int n;

	n = 2;
	//isPrime(n);
	//eratos(n);

	return 0;
}