/*
�ǽ���:�ش� �Լ��� ȣ���ϰ�, �Լ� ȣ���� ������� ��ȯ �޾�
	   main() �Լ����� �ִ밪�� ����ϴ� ���α׷��� �ۼ��ϼ���(���� 26��)
������ ����: �ڿ��� ������
�ǽ���: 2020 03 22
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/

# include <stdio.h>
#include <time.h>
#define MAX_ELEMENTS 100

int find_max_score( int *ptr_score , int *num ) {
	int i, tmp;
	tmp = ptr_score[0];
	for (i = 0; i < *num; i++) {
		if (ptr_score[i] > tmp) tmp = ptr_score[i];
	}
	return tmp;
}

int main() {
	clock_t start_point, end_point;
	int scnaf_number;
	int score[MAX_ELEMENTS];
	printf("���� ������ ������ �Է����ּ���!! \n");
	scanf_s("%d",&scnaf_number);
	printf("���ϴ� ���ڸ� �Է����ּ���!! \n");
	for (int i = 0; i < scnaf_number; i++) {
		scanf_s("%d",&score[i]);
	}
	start_point = clock();
	printf("�ִ밪�� ã�����Դϴ�\n");
	end_point = clock();
	int result = find_max_score(score,&scnaf_number);
	//printf("���α׷� ���� �ð� ���� ��� %.10f\n", (double)(end_point - start_point) / CLOCKS_PER_SEC);
	
	printf("�ִ밪�� :  %d\n", result);
	return 0;
}

















//
