/*
실습명:교과서 2.2 함수의 매개변수로서 변수와 배열
교수님 성함: 박웅규 교수님
실습일: 2020 04 01
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/
#include <stdio.h>

void copy_array(int a[] , int b[], int number){
	for (int j = 0; j < number; j++) {
		b[j] = a[j];
	}
}

void copy_variable(int a, int b) {
	b = a;
}


void main() {
	int A[5] = { 10,20,30 };
	int B[5], i, x = 2018, y = 0;
	
	copy_variable(x, y);//(실패)
	copy_array(A, B, 5);//(성공)

	printf("변수 복사 결과: x = %d , y = %d \n", x, y);
	printf("배열 복사 결과 : \n");
	for (i = 0; i < 5; i++) {
		printf("A[%d] = %d\t", i, A[i]);
		printf("B[%d] = %d\n", i, B[i]);
	}
}