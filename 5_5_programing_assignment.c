/*
실습명: 5-5장 Programing 실습!!
교수님 성함: 박웅규 교수님
실습일: 2020 04 21
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

typedef struct LinkedStack {
	Node* top;
}LinkedStack;

LinkedStack s1, s2;

Node error(char str[]) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}

int is_empty(LinkedStack *s) {
	return s->top == NULL;
}

void init_stack(LinkedStack* s) {
	s->top = NULL;
}


void push(LinkedStack* s,Elements e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;

	p->link = s->top;
	s->top = p;
}

Elements pop(LinkedStack* s) {
	Node* p;
	Elements e;
	if (is_empty(s)) {
		error("스택 공백 에러");
	}

	p = s->top;
	s->top = p->link;
	e = p->data;
	free(p);
	return e;

}

Elements peek(LinkedStack* s) {
	if (is_empty(s)) {
		error("스택 공백 에러");
	}
	return s->top->data;
}

void destory_stack(LinkedStack* s) {
	while (is_empty(s) == 0) {
		pop(s);
	}
}

int size(LinkedStack* s) {
	Node* p;
	int count = 0;
	for (p = s->top; p != NULL; p = p->link) count++;
	return count;
}

void print_stack(LinkedStack* s,char* msg) {
	Node* p;
	printf("%s[%2d] = ", msg, size(s));
	for (p = s->top; p != NULL; p = p->link) printf("%2d", p->data);

	printf("\n");
}

void main() {
	int i;
	init_stack(&s1);
	init_stack(&s2);

	for (i = 1; i < 10; i++) {
		push(&s1,i);
		push(&s2,i);
	}

	print_stack(&s1,"연결된 stack 9회");
	printf("\tstack1 pop() --> %d\n", pop(&s1));
	printf("\tstack1 pop() --> %d\n", pop(&s1));
	printf("\tstack1 pop() --> %d\n", pop(&s1));
	print_stack(&s1,"연결된 stack1  3회");

	destory_stack(&s1);
	print_stack(&s1,"연결된 stack1 destory");
	
	print_stack(&s2,"연결된 stack2 9회");
	printf("\tstack2 pop() --> %d\n", pop(&s2));
	printf("\tstack2 pop() --> %d\n", pop(&s2));
	printf("\tstack2 pop() --> %d\n", pop(&s2));
	printf("\tstack2 pop() --> %d\n", pop(&s2));
	printf("\tstack2 pop() --> %d\n", pop(&s2));
	print_stack(&s2,"연결된 stack2  5회");

	destory_stack(&s2);
	print_stack(&s2,"연결된 stack2 destory");
}
