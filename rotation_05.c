/*
실습명: 피보나치 수열 시간 측정
교수님 성함: 박웅규 교수님
실습일: 2020 05 04
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
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
	printf("%f 초 입니다\n", duration);

	start = clock();
	ret = fib(i);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Iteration (Fibo %d) : %d\n", i, ret);
	printf("%f 초 입니다\n", duration);

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