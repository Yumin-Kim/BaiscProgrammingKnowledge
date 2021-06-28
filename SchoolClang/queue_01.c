/*
�ǽ���:128p  ť �ǽ�
������ ����: �ڿ��� ������
�ǽ���: 2020 04 13
�а� : ��Ƽ �̵�� �а�
�й� : 201610309a
�̸� : ������
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
		error("ť ��ȭ ����");
	}
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}

Elements dequeue() {
	if (is_empty()) {
		error(" ť ���� ���� ");
	}
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}

Elements peek() {
	if (is_empty()) {
		error("ť ���� ����");
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
	print_queue("���� ť enqueue 9 ȸ");
	printf("\t dequeue()-> %d\n", dequeue());
	printf("\t dequeue()-> %d\n", dequeue());
	printf("\t dequeue()-> %d\n", dequeue());
	print_queue("���� zn dequeue 3ȸ");
}


