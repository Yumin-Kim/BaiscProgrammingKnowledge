/*
�ǽ���:18�� �ǽ�!!
������ ����: �ڿ��� ������
�ǽ���: 2020 04 12
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef char Elements;
Elements data[MAX_STACK_SIZE];
int top;
void init_stack() { top = -1; }
void push(Elements e) {
	data[++top] = e;
}
Elements pop() {
	return data[top--];
}

int main() {
	char str[100];
	init_stack();
	printf("100 ���� �̳��� ���ϴ� ���ڸ� �Է����ּ���!! \n");
	scanf("%s", str);
	printf("�Է��� ���ڴ� : %s\n", str);
	for (int i = 0; i < strlen(str); i++) {
		push(str[i]);
	}
	for (int i = top; i >= 0; i--) {
		printf("%c", pop());
	}
	return;
}
















/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef int Elements;
typedef struct {
	Elements stack[MAX_STACK_SIZE];
	int top;
} StackType;


void init_stack(StackType* s) { s->top = -1; }
int is_empty(StackType* s) { return s->top == -1; }
int is_full(StackType* s) { return (s->top == MAX_STACK_SIZE - 1); }

void push(StackType* s, Elements item) {
	if (is_full(s)) {
		printf("���� ��ȭ ����!!\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

Elements peek(StackType* s) {
	if (is_empty(s)) {
		printf("���� ���� ����!!\n");
		return;
	}
	else s->stack[s->top];
}

Elements pop(StackType* s) {
	if (is_empty(s)) {
		printf("���� ���� ����\m");
		return;
	}
	else return s->stack[(s->top)--];
}

int palind(char str[]) {
	StackType s;
	int i;
	char ch, chs;
	int len = strlen(str);
	init_stack(&s);

	for (i = 0; i < len; i++) {
		ch = str[i];
		if (ch == ' ' || ch == ',') continue;
		ch = tolower(ch);
		push(&s, ch);
	}

	for (i = 0; i < len; i++) {
		ch = str[i];
		if (ch == ' ' || ch == ',') continue;
		ch = tolower(ch);
		chs = pop(&s);
		if (ch != chs) return 0;
	}
	return 1;
}

int main() {

	StackType s;
	char str[MAX_STACK_SIZE];
	int check;
	printf("���ڿ��� �Է��ϼ��� \n");
	scanf("%s", str);
	check = palind(str);
	if (check) printf("ȸ�� \n");
	else printf("ȸ�� �ƴ� \n");
	return 0;
}
*/
