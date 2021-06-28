/*
실습명:heap_01_실습!!
교수님 성함: 박웅규 교수님
실습일: 2020 05 27
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEAP_NODE	100001
#define HEAP_DATA_SIZE  100000

void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}

typedef int HNode;
#define Key(n)   (n) 

HNode heap[MAX_HEAP_NODE];
int heap_size;

#define Parent(i) (heap[i/2])	
#define Left(i) (heap[i*2])	
#define Right(i) (heap[i*2+1])	

void init_heap() { heap_size = 0; }
int is_empty_heap() { return heap_size == 0; }
int is_full_heap() { return (heap_size == MAX_HEAP_NODE - 1); }
HNode find_heap() { return heap[1]; }

void insert_heap(HNode n)
{
	int i;
	if (is_full_heap()) return;
	i = ++(heap_size);
	while (i != 1 && Key(n) > Key(Parent(i))) {
		heap[i] = Parent(i);
		i /= 2;
	}
	heap[i] = n;
}

HNode delete_heap()
{
	HNode hroot, last;
	int parent = 1, child = 2;

	if (is_empty_heap() != 0)
		error("힙 트리 공백 에러");

	hroot = heap[1];
	last = heap[heap_size--];
	while (child <= heap_size) {
		if (child < heap_size && Key(Left(parent)) < Key(Right(parent)))
			child++;
		if (Key(last) >= Key(heap[child]))
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = last;
	return hroot;
}

void print_array(int a[], int n, char* msg)
{
	int i;
	printf("%10s: ", msg);
	for (i = 0; i < n; i++)
		printf("%3d", a[i]);
	printf("\n");
}

int main(void)
{
	clock_t start, finish;
	double duration, total = 0, avg;
	long seed;
	int	i, k, data[HEAP_DATA_SIZE];

	seed = time(NULL);
	srand(seed);
	for (k = 0; k < 10; k++)
	{
		for (i = 0; i < HEAP_DATA_SIZE; i++)
			data[i] = rand() % 10000;
		/*
			print_array(data, HEAP_DATA_SIZE, "정렬 전");
		*/
		start = clock();

		init_heap();
		for (i = 0; i < HEAP_DATA_SIZE; i++)
			insert_heap(data[i]);
		for (i = (HEAP_DATA_SIZE - 1); i >= 0; i--)
			data[i] = Key(delete_heap());

		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		/*
			print_array(data, HEAP_DATA_SIZE, "정렬 후");
		*/  total += duration;
	}
	avg = total / 10.0;
	printf("%f 초입니다.\n", avg);
	return 0;
}

