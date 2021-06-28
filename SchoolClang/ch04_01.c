/*
�ǽ���:������ 85p �ǽ�!!
������ ����: �ڿ��� ������
�ǽ���: 2020 04 06
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int Elements;

Elements data[MAX_STACK_SIZE];
int top;

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}
void init_stack() { top = -1; }
int is_empty() { return top == -1; }
int is_full() { return top == MAX_STACK_SIZE; }
int size() { return top + 1; }

void push(Elements e) {
	if (is_full())  error("���� ��ȭ ����");
	data[++top] = e;
}

Elements pop() {
	if (is_empty())	 error("���� ���� ����");
	return data[top--];
}

Elements peek() {
	if (is_empty) error("���� ���� ����");
	return data[top];
}

void print_stack(char msg[]) {
	int i;
	printf("%s[%2d]= ", msg, size());
	for (i = 0; i < size(); i++) printf("%2d", data[i]);
	printf("\n");
}

void main() {
	init_stack();
	int i;
	for (i = 1; i < 10; i++) push(i);
	print_stack("���� push 9ȸ");
	printf("\ttop() --> %d\n", pop());
	printf("\ttop() --> %d\n", pop());
	printf("\ttop() --> %d\n", pop());
	print_stack("���� pop 3ȸ");
}


















