/*
�ǽ���: 5-5�� �ǽ�!!
������ ����: �ڿ��� ������
�ǽ���: 2020 04 20
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
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
		error("���� ���� ����");
	}

	p = top;
	top = p->link;
	e = p->data;
	free(p);
	return e;

}

Elements peek() {
	if (is_empty()) {
		error("���� ���� ����");
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

	print_stack("����� stack 9ȸ");
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	print_stack("����� stack  3ȸ");

	destory_stack();
	print_stack("����� stack destory");
}












