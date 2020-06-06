/*
실습명:sortall_measure(실습)
교수님 성함: 박웅규 교수님
실습일: 2020 06 06
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,t)	((t)=(x),(x)=(y),(y)=(t))
#define MAX_SIZE	100000   /* for merge sort  */
#define DATA_SIZE   100000
#define TRIAL 1  /* The number of measurement testing */	

void printArray(int arr[], int n, char* str)
{
	int i;
	printf("%s = ", str);
	for (i = 0; i < n; i++) printf(" %5d", arr[i]);
	printf("\n\n");
}
void printStep(int arr[], int n, int val)
{
	int i;
	printf("  Step %2d = ", val);
	for (i = 0; i < n; i++) printf("%3d", arr[i]);
	printf("\n");
}

/* Insertion  Sort   */
void insertion_sort(int list[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
		/*	  	  printStep(list, n, i);  */
	}
}

/* Shell Sort  */
static void sortGapInsertion(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}

void shell_sort(int list[], int n)
{
	int i, gap, count = 0;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++)
			sortGapInsertion(list, i, n - 1, gap);
		/*	  	  printStep(list, n, ++count);	*/
	}
}

/* Merge Sort */
static void merge(int list[], int left, int mid, int right)
{
	int i, j, k = left, l;
	static int sorted[MAX_SIZE];

	for (i = left, j = mid + 1; i <= mid && j <= right; )
		sorted[k++] = (list[i] <= list[j]) ? list[i++] : list[j++];

	if (i > mid)
		for (l = j; l <= right; l++, k++)
			sorted[k] = list[l];
	else
		for (l = i; l <= mid; l++, k++)
			sorted[k] = list[l];

	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

/* Quick Sort   */
/* int partition(int list[], int left, int right)
{
	int tmp;
	int low = left + 1;
	int high = right;
	int pivot = list[left];
	while (low < high) {
		for (; low <= right && list[low] < pivot; low++);
		for (; high >= left  && list[high]> pivot; high--);
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
int partition(int list[], int left, int right)
{
	int pivot, tmp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (low <= right && list[low] < pivot);
		do
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], tmp);
	} while (low < high);

	SWAP(list[left], list[high], tmp);
	return high;
}

void quick_sort(int list[], int left, int right)
{
	int q;
	if (left < right) {
		q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

/*  Main  */
int main(void)
{

	clock_t start, finish;
	double duration;
	double insert_total = 0, shell_total = 0, merge_total = 0, quick_total = 0;
	int list[DATA_SIZE], dcopy[DATA_SIZE];
	int i, j;

	srand((unsigned)time(NULL));

	for (i = 0; i < TRIAL; i++) {
		for (j = 0; j < DATA_SIZE; j++) {
			list[j] = rand();
			dcopy[j] = list[j];
		}
		/*	printArray(list, DATA_SIZE, "Original "); */

		/* Insertion sort  */
		for (j = 0; j < DATA_SIZE; j++) /* for test with same data */
			list[j] = dcopy[j];
		start = clock();
		insertion_sort(list, DATA_SIZE);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		insert_total += duration;
		/*	  printArray(list, DATA_SIZE, "Insertion");  */


		/* Shell sort  */
		for (j = 0; j < DATA_SIZE; j++)  /* for test with same data */
			list[j] = dcopy[j];
		start = clock();
		shell_sort(list, DATA_SIZE);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		shell_total += duration;
		/*	  printArray(list, DATA_SIZE, "ShellSort");  */

		/* Merge sort  */
		for (j = 0; j < DATA_SIZE; j++)  /* for test with same data */
			list[j] = dcopy[j];
		start = clock();
		merge_sort(list, 0, DATA_SIZE - 1);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		merge_total += duration;
		/*	  printArray(list, DATA_SIZE, "MergeSort");   */

		/* Quick sort   */
		for (j = 0; j < DATA_SIZE; j++)  /* for test with same data */
			list[j] = dcopy[j];
		start = clock();
		quick_sort(list, 0, DATA_SIZE - 1);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		quick_total += duration;
		/* printArray(list, DATA_SIZE, "Original ");  */
	}
	printf("삽입 정렬 평균 시간 : %.6lf  \n\n", insert_total / TRIAL);
	printf("쉘 정렬 평균 시간 : %.6lf  \n\n", shell_total / TRIAL);
	printf("병합 정렬 평균 시간 : %.6lf  \n\n", merge_total / TRIAL);
	printf("퀵 정렬 평균 시간 : %.6lf  \n\n", quick_total / TRIAL);

	return 0;
}




