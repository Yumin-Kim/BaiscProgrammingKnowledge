/*
실습명: 5-5장 실습!!
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

Node* top = NULL;

Node error(char str[]) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}

int is_empty() {
	return top == NULL;
}

void init_stack() {
	top = NULL;
}


void push(Elements e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;

	p->link = top;
	top = p;
}

Elements pop() {
	Node* p;
	Elements e;
	if (is_empty()) {
		error("스택 공백 에러");
	}

	p = top;
	top = p->link;
	e = p->data;
	free(p);
	return e;

}

Elements peek() {
	if (is_empty()) {
		error("스택 공백 에러");
	}
	return top->data;
}

void destory_stack() {
	while (is_empty() == 0) {
		pop();
	}
}

int size() {
	Node* p;
	int count = 0;
	for (p = top; p != NULL; p = p->link) count++;
	return count;
}

void print_stack(char *msg) {
	Node* p;
	printf("%s[%2d] = ", msg, size());
	for (p = top; p != NULL; p = p->link) printf("%2d", p->data);

	printf("\n");
}

void main() {
	int i;
	init_stack();

	for (i = 1; i < 10; i++) {
		push(i);
	}

	print_stack("연결된 stack 9회");
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	print_stack("연결된 stack  3회");

	destory_stack();
	print_stack("연결된 stack destory");
}












