/*
�ǽ���:154p  ť �ǽ�
������ ����: �ڿ��� ������
�ǽ���: 2020 04 13
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef int Elements;
typedef struct CircularQueue {
	Elements data[MAX_QUEUE_SIZE];
	int front;
	int rear;
} Queue;

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

void init_queue(Queue *q) { q->front = q->rear = 0; ; }
int is_empty(Queue* q) {
	return q->front == q->rear;
}
int is_full(Queue* q) {
	return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

int size(Queue* q) {
	return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void enqueue(Queue* q,Elements val) {
	if (is_full(q)) {
		error("ť ��ȭ ����");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = val;
}

Elements dequeue(Queue* q) {
	if (is_empty(q)) {
		error(" ť ���� ���� ");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

Elements peek(Queue* q) {
	if (is_empty(q)) {
		error("ť ���� ����");
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void print_queue(Queue* q,char msg[]) {
	int i, maxi = q->rear;
	if (q->front >= q->rear) maxi += MAX_QUEUE_SIZE;
	printf("%s[%2d]= ", msg, size(q));
	for (i = q->front + 1; i <= maxi; i++) {
		printf("%2d", q->data[i % MAX_QUEUE_SIZE]);
	}
	printf("\n");
}

void main() {
	Queue q;
	int i;
	init_queue(&q);
	for (i = 1; i < 10; i++) {
		enqueue(&q,i);
	}
	print_queue(&q,"���� ť enqueue 9 ȸ");
	printf("\t dequeue()-> %d\n", dequeue(&q));
	printf("\t dequeue()-> %d\n", dequeue(&q));
	printf("\t dequeue()-> %d\n", dequeue(&q));
	print_queue(&q,"���� zn dequeue 3ȸ");
}


