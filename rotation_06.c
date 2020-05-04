/*
실습명: 하노이 타워!!
교수님 성함: 박웅규 교수님
실습일: 2020 05 04
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/

#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1) printf("원판 1을 %c 에서 %c으로 옯긴다 \n", from, to);
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("원판 %d을 %c에서 %c으로 옯긴다 \n",n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}

void main() { hanoi_tower(4, 'A', 'B', 'C'); }

