/*
실습명: 5-8장 실습!!
교수님 성함: 박웅규 교수님
실습일: 2020 04 20
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Elements;
typedef struct LinkedNode {
	Elements data;
	struct LinkendNode* link;
} Node;

Node* front = NULL;
Node* rear = NULL;

Node error(char str[]) {
	fprintf(stderr,"%s\n",str);
	exit(1);
}

int is_empty() {
	return front == NULL;
}

void init_queue() {
	front = rear = NULL;
}

int size() {
	Node* p;
	int count = 0;
	for (p = front; p != NULL; p = p->link) count++;
	return count;
}

void enqueue(Elements e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->link = NULL;

	if (is_empty()) front = rear = p;
	else
	{
		rear->link = p;
		rear = p;
	}

}

Elements dequeue() {
	Node* p;
	Elements e;

	if (is_empty()) {
		error("큐 공백 에러");
	}

	p = front;
	front = front->link;
	if (front == NULL) rear = NULL;
	e = p->data;
	free(p);
	return e;
}

Elements peek() {
	if (is_empty()) {
		error("큐 공백 에러");
	}
	return front->data;
}

void destory_queue() {
	while (is_empty() == 0) {
		dequeue();
	}
}

void print_queue(char *msg) {
	Node* p;
	printf("%s[%2d] = ", msg, size());
	for (p = front; p != NULL; p = p->link) printf("%2d", p->data);
	printf("\n");
}

void main() {
	int i;
	init_queue();

	for (i = 1; i < 10; i++) {
		enqueue(i);
	}

	print_queue("연결된 큐 enqueue 9회");
	printf("\tdequeue() --> %d\n",dequeue());
	printf("\tdequeue() --> %d\n",dequeue());
	printf("\tdequeue() --> %d\n",dequeue());

	print_queue("연결된 큐 dequeue 3회");

	destory_queue();
	print_queue("연결된 큐 destory");
}












