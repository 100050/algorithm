#include <stdio.h>
#include <stdlib.h>

// �Ϲ����� ���
int isPrime(int n) {
	int i, cnt;
	cnt = 0;
	for (i = 1; i*i < n; i++) {
		if (n % i == 0)
			cnt++;
	}
	if (cnt == 1)
		return 1;
	else
		return 0;
}

// �����佺�׳׽��� ü�� �̿��� ���
int eratos(int n) {
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
		return 1;
	else
		return 0;

	free(arr);
}