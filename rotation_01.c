/*
�ǽ���:���丮�� ��� �� ���!!!!
������ ����: �ڿ��� ������
�ǽ���: 2020 05 04
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/

#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
	printf("factorial(%d)\n", n);
	if (n == 1)return 1;
	else return (n * factorial(n - 1));
}

int factorial_iter(int n) {
	int k, result = 1;
	for (k = n; k > 0; k--) {
		result *= k;
	}
	return result;
}


int main() {
	
	factorial(3);
	printf("factorial_iter(3)  >> result = %d ", factorial_iter(3));
	return 0;
}


