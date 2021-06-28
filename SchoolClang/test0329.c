/*
실습명:2) 수업 시간에 실습한 최대값 구하는 알고리즘의 수행 시간 측정
		(유의미한 수행 시간이 측정되도록 데이터 크기 적당히 변경) 프로그램을 개별적으로 작성하고, 실습하세요.
교수님 성함: 박웅규 교수님
실습일: 2020 03 30
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS  20202020
int scores[MAX_ELEMENTS];
int find_max_score(int n) { 
	int i, tmp;
	tmp = scores[0];

	for (i = 1; i < n; i++) {
		if (scores[i] > tmp) tmp = scores[i];
	}

	return tmp;
}

int main() { 
	int i ,  ret;
	clock_t start_point, end_point;
	for (i = 0; i < MAX_ELEMENTS ; i++) {
		scores[i] = i;
	}
	start_point = clock();
	ret = find_max_score(MAX_ELEMENTS);
	end_point= clock();
	printf("최댓값은 %d \n", ret);
	printf("알고리즘 수행시간 %f 초 걸렸습니다 \n", (double)(end_point - start_point)/CLOCKS_PER_SEC);
	return 0;
}
