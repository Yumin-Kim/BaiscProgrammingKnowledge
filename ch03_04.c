/*
�ǽ���:����2.5 ���� Ǯ�� 
������ ����: �ڿ��� ������
�ǽ���: 2020 04 01
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
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
	printf("�ʱ�ȭ ����\n");
	print_complex(a);
	rest_complex(a);
	printf("�ʱ�ȭ ����\n");
	print_complex(a);
	rest_complex_ptr(&a);
	printf("�ʱ�ȭ ����(�ּҰ� ����)\n");
	print_complex(a);
}