/*
실습명: 순환적인 거듭제곱 계산함수 >> 시간 측정
교수님 성함: 박웅규 교수님
실습일: 2020 05 04
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/

#include <stdio.h>
#include <time.h>

#define MAX_CLOOK_SIZE 1000000000

double slow_power(double x, int n) {
	int i;
	double result = 1.0;
	for (i = 1; i < n; i++) {
		result *= x;
	}
	return result;
}

double power(double x, int n) {
	if (n == 0) return 1;
	else if ((n % 2) == 0) {
		printf("");
		return power(x * x, n / 2);
	}
	else {
		return x * power(x * x, (n - 1) / 2);
	}
}

int main() {
	int t, ret;
	clock_t start, end, start_,end_;
	start = clock();
	slow_power(3, MAX_CLOOK_SIZE);
	end = clock();
	printf("slow_power >> %f\n", (double)(end-start)/CLOCKS_PER_SEC);
	start_ = clock();
	power(3, MAX_CLOOK_SIZE);
	end_ = clock();
	printf("fast_power%.10f", (double)(end_ - start_) / CLOCKS_PER_SEC);

}
