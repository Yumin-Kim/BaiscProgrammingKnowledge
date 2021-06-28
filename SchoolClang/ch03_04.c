/*
실습명:교제2.5 문제 풀이 
교수님 성함: 박웅규 교수님
실습일: 2020 04 01
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/
#include <stdio.h>

typedef struct {
	double real;
	double imag;
}Complex;

void print_complex(Complex c) {
	printf("%4.1f + %4.1f \n", c.real,c.imag);
}

void rest_complex(Complex c) {
	c.real = c.imag = 0;
}

void rest_complex_ptr(Complex* c) {
	(*c).real = c->imag = 0;
}

void main() {
	Complex a = { 1.0,2.0 };
	printf("초기화 이전\n");
	print_complex(a);
	rest_complex(a);
	printf("초기화 이후\n");
	print_complex(a);
	rest_complex_ptr(&a);
	printf("초기화 이후(주소값 참조)\n");
	print_complex(a);
}