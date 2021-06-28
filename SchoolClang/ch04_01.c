/*
실습명:교과서 85p 실습!!
교수님 성함: 박웅규 교수님
실습일: 2020 04 06
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
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
	if (is_full())  error("스택 포화 에러");
	data[++top] = e;
}

Elements pop() {
	if (is_empty())	 error("스택 공백 에러");
	return data[top--];
}

Elements peek() {
	if (is_empty) error("스택 공백 에러");
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
	print_stack("스택 push 9회");
	printf("\ttop() --> %d\n", pop());
	printf("\ttop() --> %d\n", pop());
	printf("\ttop() --> %d\n", pop());
	print_stack("스택 pop 3회");
}


















