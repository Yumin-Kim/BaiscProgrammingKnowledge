/*
실습명: 원하는 숫자 입력후 원하는 숫자까지의 함!!
교수님 성함: 박웅규 교수님
실습일: 2020 05 04
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/

#include <stdio.h>
#include <stdlib.h>
int sum_iter(int num);
int sum_result(int num);

int main() {
	int num, sum;
	printf("Please , enter a number");
	scanf("%d", &num);

	sum = sum_iter(num);
	printf("Iteration 1 + 2 + 3 +4 ,,, + %d =  %d \n",num , sum);
	
	sum = sum_result(num);
	printf("Recursion 1 + 2 + 3 +4 ,,, + %d =  %d \n",num , sum);

	return 0;
}

int sum_iter(int num) {
	int i, sum = 0;
	for (i = 1; i <= num; i++) {
		sum += i;
	}
	return sum;
}

int sum_result(int num) {
	if (num == 1) return 1;
	else return(num + sum_result(num - 1));
}
