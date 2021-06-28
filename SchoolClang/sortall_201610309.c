/*
실습명:sortall(실습)
교수님 성함: 박웅규 교수님
실습일: 2020 06 08
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/
#include <stdio.h>
#define SWAP(x,y,t)	((t)=(x),(x)=(y),(y)=(t))

void printArray(int arr[], int n, char* str)
{
	int i;
	printf("%s = ", str);
	for (i = 0; i < n; i++) printf("%3d", arr[i]);
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
		printStep(list, n, i);
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
		printStep(list, n, ++count);
	}
}

/* Merge Sort */
#define MAX_SIZE	1024
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
	int 	i, list[9] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 }, dcopy[9];

	printArray(list, 9, "Original ");
	for (i = 0; i < 9; i++)
		dcopy[i] = list[i];

	/* Insertion sort  */
	insertion_sort(list, 9);
	printArray(list, 9, "Insertion");

	/* Shell sort  */
	for (i = 0; i < 9; i++)
		list[i] = dcopy[i];
	shell_sort(list, 9);
	printArray(list, 9, "ShellSort");

	/* Merge sort */
	for (i = 0; i < 9; i++)
		list[i] = dcopy[i];
	merge_sort(list, 0, 8);
	printArray(list, 9, "MergeSort");

	/* Quick sort  */
	for (i = 0; i < 9; i++)
		list[i] = dcopy[i];
	quick_sort(list, 0, 8);
	printArray(list, 9, "QuickSort");

	return 0;
}


