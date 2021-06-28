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
	fprintf(stderr, "%s\n", str);
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

void print_queue(char* msg) {
	Node* p;
	printf("%s[%2d] = ", msg, size());
	for (p = front; p != NULL; p = p->link) printf("%2d", p->data);
	printf("\n");
}

void main() {
	int i;
	init_queue();

	while(1) {
		printf("양의 정수를 입력하세요(종료 : -1)");
		scanf("%d", &i);
		if (i >= 0) {
			enqueue(i);
		}
		if (i < 0) {
			printf("End\n");
			Node* p;
			for (p = front; p != NULL; p = p->link) {
				printf("%d >>",p->data);
			}
			printf("NULL");
			return 0;
		};
	}
}












