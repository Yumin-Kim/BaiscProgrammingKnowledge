/*
�ǽ���:q_sort(�ǽ�)
������ ����: �ڿ��� ������
�ǽ���: 2020 06 08
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define MAX_WORD_SIZE 50
#define MAX_MEANING_SIZE 500
#define MAX_SIZE 1000

/*  ���� ������ �ϳ��� �ܾ� ���� ������ ���� ����ü Ÿ�� */
typedef struct {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
} element;



/* Quick Sort */
/*  �� ������ ���� ũ�� �� �Լ�
	e1 > e2 -> 1
	e1 == e2 -> 0
	e2 < e2 -> -1     */
int compare(element e1, element e2)
{
	return strcmp(e1.word, e2.word);
}
/*  �� ���Ŀ��� �ǹ��� �������� �� ���� �κ� ����Ʈ�� �����ϴ� �Լ�    */
/* int partition(element list[], int left, int right)
{
	element tmp;
	int low = left + 1;
	int high = right;
	element pivot = list[left];
	while (low < high) {
		for (; low <= right && compare(list[low], pivot)<0 ; low++);
		for (; high >= left  && compare(list[high],pivot)>0; high--);
		if (low < high)	{
			SWAP(list[low], list[high], tmp);
			low++;
			high--;
		}
	}
	SWAP(list[left], list[high], tmp);
	return high;
}
*/

int partition(element list[], int left, int right)
{
	element pivot, tmp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (low <= right && compare(list[low], pivot) < 0);
		do
			high--;
		while (high >= left && compare(list[high], pivot) > 0);
		if (low < high) SWAP(list[low], list[high], tmp);
	} while (low < high);

	SWAP(list[left], list[high], tmp);
	return high;
}

void quick_sort(element list[], int left, int right)
{
	int q;
	if (left < right) {
		q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

/*  ������ ����� �ܾ� ������ ����ϴ� �Լ�   */
void print(element list[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf(" %s:%s\n", list[i].word, list[i].meaning);
	}
	printf("\n");
}

int main(void)
{
	int i;
	element e;
	/* ���� ���� �迭(��ü �ܾ� ������ ����)   */
	element list[MAX_SIZE];
	int  n = 0;   /*  ���� ���� �迭�� ����� �ܾ� ��  */

	for (i = 0; i < 5; i++) {
		printf("�ܾ�:");
		gets(e.word);
		printf("�ǹ�:");
		gets(e.meaning);
		list[i] = e;
		n++;
	}
	printf("***  Before quick sort ***\n");
	print(list, n);
	/* Quick sort  */
	quick_sort(list, 0, n - 1);
	printf("***  After quick sort ***\n");
	print(list, n);

	return 0;
}

