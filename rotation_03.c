/*
실습명: 최댓값 구하기 반복 순환
교수님 성함: 박웅규 교수님
실습일: 2020 05 04
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS  5
#define MAX(a,b) ( (a) > (b) ) ? (a) : (b)

int find_max_score_iter(int score[], int n);
int find_max_score_recur(int score[], int n);

int main() {
	int i, ret;
	int seed;
	int score[MAX_ELEMENTS];

	seed = time(NULL);
	srand(seed);
	for (i = 0; i < MAX_ELEMENTS; i++)
		score[i] = rand();

	ret = find_max_score_iter(score , MAX_ELEMENTS);
	printf("Interation : Max score is %d \n", ret);
	ret = find_max_score_recur(score, MAX_ELEMENTS);
	printf("Recursion : Max score is %d \n", ret);
	return 0;
}

int find_max_score_iter(int score[], int n) {
	int i, tmp;
	tmp = score[0];
	for (i = 1; i < n; i++) {
		printf("%d\\n", score[i]);
		if (score[i] > tmp) tmp = score[i];
	}
	return tmp;
}
int find_max_score_recur(int score[], int n) {
	if (n == 0) return score[0];
	else return(MAX(score[n - 1], find_max_score_recur(score, n - 1)));
}
