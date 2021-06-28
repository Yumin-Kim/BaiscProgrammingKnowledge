/*
실습명:교과서 88p 실습!!
교수님 성함: 박웅규 교수님
실습일: 2020 04 06
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef struct student {
	int id;
	char name[32];
	char dept[32];
} Student ;

typedef Student Elements;

typedef struct stack {
	Elements data[MAX_STACK_SIZE];
	int top;
} Stack;

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}
void init_stack(Stack *s) { s->top = -1; }
int is_empty(Stack* s) { return s->top == -1; }
int is_full(Stack* s) { return s->top == MAX_STACK_SIZE; }
int size(Stack* s) { return s->top + 1; }

void push(Stack* s,Elements e) {
	if (is_full(s))  error("스택 포화 에러");
	s->data[++s->top] = e;
}

Elements pop(Stack* s) {
	if (is_empty(s))	 error("스택 공백 에러");
	return s->data[s->top--];
}

Elements peek(Stack* s) {
	if (is_empty(s)) error("스택 공백 에러");
	return s->data[s->top];
}

void print_stack(Stack* s,char msg[]) {
	int i;
	printf("%s[%2d]= ", msg, size(s));
	for (i = 0; i < size(s); i++) {
		printf("\n\t%-15d %-10s %-20s" , s->data[i].id , s->data[i].name , s->data[i].dept);
	} 
	printf("\n");
}

Student get_student(int id, char name[], char dept[]) {
	Student s;
	s.id = id;
	strcpy(s.name , name);
	strcpy(s.dept, dept);
	return s;
}

void main() {
	Stack s1 , s2; //배열 처럼 기본 주소 값을 가르키지 않고 있다 >> &s1 >> 이런식으로 지정할 필요가 있다 
	int arr[10][20];
	printf("%d", sizeof arr);
	printf("first Stack \n");
	init_stack(&s1);
	push(&s1,get_student(2018130007, "홍길동", "컴퓨터 공학과"));
	push(&s1,get_student(2018130100, " 이순신", "기계공학과"));
	push(&s1,get_student(2018130135, "김연아", "체육과"));
	push(&s1,get_student(2018130135, "황희", "법학과"));
	print_stack(&s1,"스택 push 4회");
	pop(&s1);
	print_stack(&s1,"스택 pop 1회");
	printf("second Stack \n");
	init_stack(&s2);
	push(&s2, get_student(2018130100, " 이순신", "기계공학과"));
	push(&s2, get_student(2018130007, "홍길동", "컴퓨터 공학과"));
	print_stack(&s2, "스택2 현황");


}






