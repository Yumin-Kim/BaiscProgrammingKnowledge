/*
�ǽ���: �ϳ��� Ÿ��!!
������ ����: �ڿ��� ������
�ǽ���: 2020 05 04
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/

#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1) printf("���� 1�� %c ���� %c���� ����� \n", from, to);
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("���� %d�� %c���� %c���� ����� \n",n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}

void main() { hanoi_tower(4, 'A', 'B', 'C'); }

