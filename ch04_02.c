/*
�ǽ���:������ 88p �ǽ�!!
������ ����: �ڿ��� ������
�ǽ���: 2020 04 06
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
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
	if (is_full(s))  error("���� ��ȭ ����");
	s->data[++s->top] = e;
}

Elements pop(Stack* s) {
	if (is_empty(s))	 error("���� ���� ����");
	return s->data[s->top--];
}

Elements peek(Stack* s) {
	if (is_empty(s)) error("���� ���� ����");
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
	Stack s1 , s2; //�迭 ó�� �⺻ �ּ� ���� ����Ű�� �ʰ� �ִ� >> &s1 >> �̷������� ������ �ʿ䰡 �ִ� 
	int arr[10][20];
	printf("%d", sizeof arr);
	printf("first Stack \n");
	init_stack(&s1);
	push(&s1,get_student(2018130007, "ȫ�浿", "��ǻ�� ���а�"));
	push(&s1,get_student(2018130100, " �̼���", "�����а�"));
	push(&s1,get_student(2018130135, "�迬��", "ü����"));
	push(&s1,get_student(2018130135, "Ȳ��", "���а�"));
	print_stack(&s1,"���� push 4ȸ");
	pop(&s1);
	print_stack(&s1,"���� pop 1ȸ");
	printf("second Stack \n");
	init_stack(&s2);
	push(&s2, get_student(2018130100, " �̼���", "�����а�"));
	push(&s2, get_student(2018130007, "ȫ�浿", "��ǻ�� ���а�"));
	print_stack(&s2, "����2 ��Ȳ");


}






