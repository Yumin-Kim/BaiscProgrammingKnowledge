/*
�ǽ���: �������� 6��
������ ����: �ڿ��� ������
�ǽ���: 2020 05 04
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
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