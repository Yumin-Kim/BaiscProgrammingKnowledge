/*
�ǽ���:2) ���� �ð��� �ǽ��� �ִ밪 ���ϴ� �˰����� ���� �ð� ����
		(���ǹ��� ���� �ð��� �����ǵ��� ������ ũ�� ������ ����) ���α׷��� ���������� �ۼ��ϰ�, �ǽ��ϼ���.
������ ����: �ڿ��� ������
�ǽ���: 2020 03 30
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS  20202020
int scores[MAX_ELEMENTS];
int find_max_score(int n) { 
	int i, tmp;
	tmp = scores[0];

	for (i = 1; i < n; i++) {
		if (scores[i] > tmp) tmp = scores[i];
	}

	return tmp;
}

int main() { 
	int i ,  ret;
	clock_t start_point, end_point;
	for (i = 0; i < MAX_ELEMENTS ; i++) {
		scores[i] = i;
	}
	start_point = clock();
	ret = find_max_score(MAX_ELEMENTS);
	end_point= clock();
	printf("�ִ��� %d \n", ret);
	printf("�˰��� ����ð� %f �� �ɷȽ��ϴ� \n", (double)(end_point - start_point)/CLOCKS_PER_SEC);
	return 0;
}
