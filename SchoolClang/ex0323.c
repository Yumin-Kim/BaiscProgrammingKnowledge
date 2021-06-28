//폴더 자체는 C 소스 코드
#include <stdio.h>//헤더 파일 >> 컴파일러가 가지고 있는 라이브러리에서 가지고옴
#include <stdlib.h>
#include <time.h>
//stdio.h(standard(표준) I/O)표준 입출력 라이브러리
//#으로 시작하는 문장은 전처리기 관련 문장으로 전처리기에게 원하는 파일 가져오라고 명령
#define MAX_ELEMENTS  100//(매크로 상수로 별칭을 지정한다)
int scores[MAX_ELEMENTS]; // 전역변수
int find_max_score(int n) { //
	int i, tmp;
	tmp = scores[0];

	for (i = 1; i < n; i++) {
		if (scores[i] > tmp) tmp = scores[i];
	}

	return tmp;
}
	//void srand(unsigned int seed); >>seed값은 계속 변화는 값을 주어야한다

int main() { // 진입함수
	/*
	int i ,  ret;
	for (i = 0; i < MAX_ELEMENTS ; i++) {
		scores[i] = i;
	}
	ret = find_max_score(MAX_ELEMENTS);
	printf("Max NUmber %d \n", ret);
	*/
	int random = 0;

	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		random = rand() % 9;
		printf("%d\n", random);
	}


	return 0;
}
