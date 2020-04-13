/*
�ǽ���:134p  ť �ǽ�
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

void enqueue(Elements val) {
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

void print_queue(char msg[]) {
	int i, maxi = rear;
	if (front >= rear) maxi += MAX_QUEUE_SIZE;
	printf("%s[%2d]= ", msg, size());
	for (i = front + 1; i <= maxi; i++) {
		printf("%2d", data[i % MAX_QUEUE_SIZE]);
	}
	printf("\n");
}

void init_deque() { init_queue(); }
void add_rear(Elements val) { enqueue(val); }
Elements delete_front() { return dequeue(); }
Elements get_front() { return peek(); }

void add_front(Elements val){
	if (is_empty()) {
		error(" �� ��ȭ ���� ");
	}
	data[front] = val;
	front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

Elements delete_rear() {
	int prev = rear;
	if (is_empty()) {
		error("�� ���� ����");
	}
	rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return data[prev];
}

Elements get_rear() {
	if (is_empty()) {
		error("�� ���� ����");
	}
	return data[rear];
}

void print_deque( char msg[] ) { print_queue(msg); }

void main() {
	int i;

	init_deque();
	for (int i = 0; i < 10; i++) {
		if (i % 2) add_front(i);
		else add_rear(i);
	}
	print_deque("���� �� Ȧ��-¦�� ");
	printf("\t delete_front()--> %d\n", delete_front());
	printf("\t delete_rear()--> %d\n", delete_rear());
	printf("\t delete_front()--> %d\n", delete_front());
	print_deque("���� �� ����- Ȧ¦Ȧ ");
}











