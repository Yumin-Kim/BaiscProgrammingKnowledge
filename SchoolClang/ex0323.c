//���� ��ü�� C �ҽ� �ڵ�
#include <stdio.h>//��� ���� >> �����Ϸ��� ������ �ִ� ���̺귯������ �������
#include <stdlib.h>
#include <time.h>
//stdio.h(standard(ǥ��) I/O)ǥ�� ����� ���̺귯��
//#���� �����ϴ� ������ ��ó���� ���� �������� ��ó���⿡�� ���ϴ� ���� ��������� ���
#define MAX_ELEMENTS  100//(��ũ�� ����� ��Ī�� �����Ѵ�)
int scores[MAX_ELEMENTS]; // ��������
int find_max_score(int n) { //
	int i, tmp;
	tmp = scores[0];

	for (i = 1; i < n; i++) {
		if (scores[i] > tmp) tmp = scores[i];
	}

	return tmp;
}
	//void srand(unsigned int seed); >>seed���� ��� ��ȭ�� ���� �־���Ѵ�

int main() { // �����Լ�
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
