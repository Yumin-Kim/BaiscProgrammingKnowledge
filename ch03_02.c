/*
�ǽ���:������ 2.2 �Լ��� �Ű������μ� ������ �迭
������ ����: �ڿ��� ������
�ǽ���: 2020 04 01
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
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
	
	copy_variable(x, y);//(����)
	copy_array(A, B, 5);//(����)

	printf("���� ���� ���: x = %d , y = %d \n", x, y);
	printf("�迭 ���� ��� : \n");
	for (i = 0; i < 5; i++) {
		printf("A[%d] = %d\t", i, A[i]);
		printf("B[%d] = %d\n", i, B[i]);
	}
}