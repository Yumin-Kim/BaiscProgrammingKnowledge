/*
실습명:2)에서 작성한 프로그램을 약간 변경하여
		데이터를 다르게 바꿔가며(10번) 알고리즘을 수행하여 평균 시간을 측정하는 프로그램을 작성하세요
교수님 성함: 박웅규 교수님
실습일: 2020 03 30
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS  2020202
#define MAX_ARRAY 20202020
int scores[MAX_ARRAY];
void find_max_score(int n) {
	int i, tmp;
	tmp = scores[0];
	for (i = 1; i < n; i++) {
		if (scores[i] > tmp) tmp = scores[i];
	}
}
int main() {
	float sumClockArray[11];
	clock_t start_point, end_point;
	int random = 0;
	float plusClock = 0;
	
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		random = rand() % 9;
		int max_Random = MAX_ELEMENTS * random;
		for (int j = 0; j < max_Random; j++) {
			scores[j] = j;
		}
		start_point = clock();
		find_max_score(max_Random);
		end_point = clock();
		sumClockArray[i] = (double)(end_point - start_point) / CLOCKS_PER_SEC;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d번째 숫자의 수행 시간입니다 %.7f \n",(i+1) , sumClockArray[i]);
		plusClock += sumClockArray[i];
	}
	printf("총합 시간입니다!! %.7f \n", plusClock);
	printf("평균 시간입니다!! %.7f \n", plusClock/10);
	return 0;
}
