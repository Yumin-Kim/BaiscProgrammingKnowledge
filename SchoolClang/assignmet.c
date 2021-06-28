/*
실습명:해당 함수를 호출하고, 함수 호출의 결과값을 반환 받아
	   main() 함수에세 최대값을 출력하는 프로그램을 작성하세요(교재 26쪽)
교수님 성함: 박웅규 교수님
실습일: 2020 03 22
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/

# include <stdio.h>
#include <time.h>
#define MAX_ELEMENTS 100

int find_max_score( int *ptr_score , int *num ) {
	int i, tmp;
	tmp = ptr_score[0];
	for (i = 0; i < *num; i++) {
		if (ptr_score[i] > tmp) tmp = ptr_score[i];
	}
	return tmp;
}

int main() {
	clock_t start_point, end_point;
	int scnaf_number;
	int score[MAX_ELEMENTS];
	printf("비교할 숫자의 갯수를 입력해주세요!! \n");
	scanf_s("%d",&scnaf_number);
	printf("원하는 숫자를 입력해주세요!! \n");
	for (int i = 0; i < scnaf_number; i++) {
		scanf_s("%d",&score[i]);
	}
	start_point = clock();
	printf("최대값을 찾는중입니다\n");
	end_point = clock();
	int result = find_max_score(score,&scnaf_number);
	//printf("프로그램 실행 시간 측정 결과 %.10f\n", (double)(end_point - start_point) / CLOCKS_PER_SEC);
	
	printf("최대값은 :  %d\n", result);
	return 0;
}

















//
