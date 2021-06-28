/*
실습명:128p  큐 실습
교수님 성함: 박웅규 교수님
실습일: 2020 04 13
학과 : 멀티 미디어 학과
학번 : 201610309a
이름 : 김유민
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef int Elements;
Elements data[MAX_QUEUE_SIZE];

int front;
int rear;

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

void init_queue() { front = rear = 0; ; }
int is_empty() {
	return front == rear;
}
int is_full() {
	return front == (rear + 1) % MAX_QUEUE_SIZE;
}

int size() {
	return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void enqueue( Elements val ) {
	if (is_full()) {
		error("큐 포화 상태");
	}
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}

Elements dequeue() {
	if (is_empty()) {
		error(" 큐 공백 에러 ");
	}
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}

Elements peek() {
	if (is_empty()) {
		error("큐 공백 에러");
	}
	return data[(front + 1) % MAX_QUEUE_SIZE];
}

void print_queue( char msg[] ) {
	int i, maxi = rear;
	if (front >= rear) maxi += MAX_QUEUE_SIZE;
	printf("%s[%2d]= ", msg, size());
	for (i = front + 1; i <= maxi; i++) {
		printf("%2d", data[i % MAX_QUEUE_SIZE]);
	}
	printf("\n");
}

void main() {
	int i = 0;
	init_queue();
	for (i = 1; i < 10; i++) {
		enqueue(i);
	}
	print_queue("선형 큐 enqueue 9 회");
	printf("\t dequeue()-> %d\n", dequeue());
	printf("\t dequeue()-> %d\n", dequeue());
	printf("\t dequeue()-> %d\n", dequeue());
	print_queue("선형 zn dequeue 3회");
}


