/*
실습명: 연습문제 6번
교수님 성함: 박웅규 교수님
실습일: 2020 05 04
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/
#include <stdio.h>

void asterisk(int i) {
	if (i > 1) {
		asterisk(i / 2);
		asterisk(i / 2);
	}
	printf("*\n");
}

int main() {
	asterisk(5);
}