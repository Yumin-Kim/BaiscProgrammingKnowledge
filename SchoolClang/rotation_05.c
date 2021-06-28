/*
�ǽ���: �Ǻ���ġ ���� �ð� ����
������ ����: �ڿ��� ������
�ǽ���: 2020 05 04
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fib(int n);
int fib_iter(int n);

int main() {
	int ret, i;
	clock_t start, end;
	double duration;

	printf("Please ,enter a number");
	scanf("%d", &i);

	start = clock();
	ret = fib(i);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Recursion (Fibo %d) : %d\n", i, ret);
	printf("%f �� �Դϴ�\n", duration);

	start = clock();
	ret = fib(i);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Iteration (Fibo %d) : %d\n", i, ret);
	printf("%f �� �Դϴ�\n", duration);

	return 0;
}

int fib(int n) {
	if (n == 0)return 0;
	if (n == 1) return 1;
	return (fib(n - 1) + fib(n - 2));
}

int fib_iter(int n) {
	int i, tmp, current, last;
	if (n < 2) return n;
	else {
		last = 0;
		current = 1;
		for (i = 2; i <= n; i++) {
			tmp = current;
			current += last;
			last = tmp;
		}
		return current;
	}
}