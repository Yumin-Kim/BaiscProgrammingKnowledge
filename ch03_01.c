/*
실습명:교과서 2.1 변수의 복사와 배열의 복사
교수님 성함: 박웅규 교수님
실습일: 2020 04 01
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/
#include <stdio.h>


void main() {
	int A[5] = { 10,20,30 };
	int B[5], i, x = 2018, y = 0;

	y = x;

	for (i = 0; i < 5; i++) B[i] = A[i];

	printf("변수 복사 결과 : x = %d , y = %d\n", x, y);
	printf("배열 복사 결과 :\n");
	for (i = 0; i < 5; i++) {
		printf("A[%d] = %d\t", i, A[i]);
		printf("B[%d] = %d\n", i, B[i]);
	}

}

