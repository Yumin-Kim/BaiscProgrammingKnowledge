/*
실습명:팩토리얼 출력 및 계산!!!!
교수님 성함: 박웅규 교수님
실습일: 2020 05 04
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/

#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
	printf("factorial(%d)\n", n);
	if (n == 1)return 1;
	else return (n * factorial(n - 1));
}

int factorial_iter(int n) {
	int k, result = 1;
	for (k = n; k > 0; k--) {
		result *= k;
	}
	return result;
}


int main() {
	
	factorial(3);
	printf("factorial_iter(3)  >> result = %d ", factorial_iter(3));
	return 0;
}


