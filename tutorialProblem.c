/*
실습명:18번 실습!!
교수님 성함: 박웅규 교수님
실습일: 2020 04 12
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
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
	printf("100 글자 이내로 원하는 글자를 입력해주세요!! \n");
	scanf("%s", str);
	printf("입력한 문자는 : %s\n", str);
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
		printf("스택 포화 상태!!\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

Elements peek(StackType* s) {
	if (is_empty(s)) {
		printf("스택 공백 상태!!\n");
		return;
	}
	else s->stack[s->top];
}

Elements pop(StackType* s) {
	if (is_empty(s)) {
		printf("스택 공백 상태\m");
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
	printf("문자열을 입력하세요 \n");
	scanf("%s", str);
	check = palind(str);
	if (check) printf("회문 \n");
	else printf("회문 아님 \n");
	return 0;
}
*/
