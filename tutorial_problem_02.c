/*
�ǽ���:12�� �ǽ�
������ ����: �ڿ��� ������
�ǽ���: 2020 04 23
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 100

typedef char Elements;
typedef struct CircularQueue {
	Elements data[100];
	int front;
	int rear;
	char strFront;
	char strRear;
} Queue;

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

void init_queue(Queue* q , char *str) {
	strcpy(q->data, str);
	q->front = q->rear = 0;
}
int is_empty(Queue* q) {
	return q->front == q->rear;
}
int is_full(Queue* q) {
	return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

int size(Queue* q) {
	return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void enqueue(Queue* q, Elements val) {
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


Elements delete_rear(Queue *q) {
	int prev = q->rear;
	if (is_empty(q)) {
		error("�� ���� ����");
	}
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

Elements delete_front(Queue* q) { return dequeue(q); }

Elements peek(Queue* q) {
	if (is_empty(q)) {
		error("ť ���� ����");
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}



void print_queue(Queue* q, char msg[]) {
	int i, maxi = q->rear;
	if (q->front >= q->rear) maxi += MAX_QUEUE_SIZE;
	printf("%s[%2d]= ", msg, size(q));
	for (i = q->front + 1; i <= maxi; i++) {
		printf("%2d", q->data[i % MAX_QUEUE_SIZE]);
	}
	printf("\n");
	
}
int palind(Queue *q,char *str) {
	int i;
	char ch, chs;
	int len = strlen(q->data);
	printf("queue size %d\n", len);
	printf("�Է��Ͻ� ���ڴ� : %s \n",str);
	for (i = 0; i < len; i++) {
		ch = str[i];
		if (ch == ' ' || ch == ',') continue;
		ch = tolower(ch);
		enqueue(q, ch);
	}
	printf("\n");
	for (i = 0; i < len; i++) {
		if (delete_front(q) == delete_rear(q)) {
			printf("%d ��°�� ��ġ �մϴ�\n",i+1);
		}
		else {
			printf("%d ��°�� ����ġ �մϴ�\n", i + 1);
			return 0;
		}
		if (size(q) == 0 || size(q) == 1) {
			return 1;
		}
		
	}
}

void compareContext(int num) {
	if (num == 1) {
		printf("ȸ���Դϴ�\n");
	}
	else {
		printf("ȸ���� �ƴմϴ�\n");
	}
}

void main() {
	Queue q1, q2,q3;
	init_queue(&q1,"Ma,dam");
	compareContext(palind(&q1, "Ma,dam"));
	init_queue(&q2, "Mb,dam");
	compareContext(palind(&q2, "Mb,dam"));
	init_queue(&q3, "RaceCar");
	compareContext(palind(&q3, "RaceCar"));

}