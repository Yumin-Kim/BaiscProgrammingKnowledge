/*
�ǽ���:2)���� �ۼ��� ���α׷��� �ణ �����Ͽ�
		�����͸� �ٸ��� �ٲ㰡��(10��) �˰����� �����Ͽ� ��� �ð��� �����ϴ� ���α׷��� �ۼ��ϼ���
������ ����: �ڿ��� ������
�ǽ���: 2020 03 30
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS  2020202
#define MAX_ARRAY 20202020
int scores[MAX_ARRAY];
void find_max_score(int n) {
	int i, tmp;
	tmp = scores[0];
	for (i = 1; i < n; i++) {
		if (scores[i] > tmp) tmp = scores[i];
	}
}
int main() {
	float sumClockArray[11];
	clock_t start_point, end_point;
	int random = 0;
	float plusClock = 0;
	
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		random = rand() % 9;
		int max_Random = MAX_ELEMENTS * random;
		for (int j = 0; j < max_Random; j++) {
			scores[j] = j;
		}
		start_point = clock();
		find_max_score(max_Random);
		end_point = clock();
		sumClockArray[i] = (double)(end_point - start_point) / CLOCKS_PER_SEC;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d��° ������ ���� �ð��Դϴ� %.7f \n",(i+1) , sumClockArray[i]);
		plusClock += sumClockArray[i];
	}
	printf("���� �ð��Դϴ�!! %.7f \n", plusClock);
	printf("��� �ð��Դϴ�!! %.7f \n", plusClock/10);
	return 0;
}
