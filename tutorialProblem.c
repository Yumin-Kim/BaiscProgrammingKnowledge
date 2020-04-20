/*
�ǽ���:
������ ����: �ڿ��� ������
�ǽ���: 2020 04 12
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
	if (is_empty()) error("���� ���� ����");
	return data[top];
}

int check_matching(char expr[]) {
	int i = 0, prev;
	char ch;
	init_stack();
	while (expr[i] != '\0') {
		ch = expr[i++];
		if (ch == '[' || ch == '(' || ch == '{') {
			push(ch);
		}
		else if (ch == ']' || ch == ')' || ch == '}') {
			if (is_empty()) return 2;
			prev = pop();
			if ((ch == ']' && prev != '[') || (ch == ')' && prev != '(') || (ch == '}' && prev != '{')) {
				return 3;
			}
		}
	}

	if (is_empty() == 0) return 1;
	return 0;
}

double calc_postfix(char expr[]) {
	char c, op;
	int i = 0;
	double val, val1, val2;
	init_stack();
	printf("%s >> \n",expr);
	while (expr[i] != '\0') {
		c = expr[i++];
		printf("%c",c);
		if (c >= '0' && c <= '9') {
			val = c - '0';
			push(val);
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			val2 = pop();
			val1 = pop();
			switch (c) {
			case '+': push(val1 + val2); break;
			case '-': push(val1 - val2); break;
			case '*': push(val1 * val2); break;
			case '/': push(val1 / val2); break;
			default:
				break;
			}
		}
		else if (c == '(') push(c);
		else if (c == ')') {
			while (is_empty() == 0) {
				op = pop();
				if (op == '(') break;
			}
		}
	}
	return pop();
}

int precedence(char op) {
	switch (op)
	{
	case'(': case ')': return 0;
	case'+': case '-': return 1;
	case'*': case '/': return 2;
	}
	return -1;
}


void infix_to_postfix(char expr[],char arr[]) {
	int i = 0;
	int j = 0;
	char c, op;
	init_stack();
	while (expr[i] != '\0') {
		c = expr[i++];
		if ((c >= '0' && c <= '9')) {
			printf("%c , %d", c, expr[i]);
			arr[j] = expr[i];
		}
		else if (c == '(') push(c);
		else if (c == ')') {
			while (is_empty() == 0) {
				op = pop();
				if (op == '(') break;
				else { printf("%c", op);}
			}
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (is_empty() == 0) {
				op = peek();
				if (precedence(c) <= precedence(op)) {
					arr[j] = expr[i];
					printf("%c", op);
					pop();
				}
				else break;
			}
			push(c);
		}
		j++;
	}
	while (is_empty() == 0) printf("%c", pop());
	printf("\n");
}

void main() {
	int errCode, i;
	char expr[100],arr[100];
	printf("���� ǥ�������� ����� ���� ���� �ּ���!! :");
	scanf("%s",expr);
	errCode = check_matching(expr);
	if (errCode == 0) printf(" ���� : %s\n ", expr);
	else printf("���� :>> �Է� %s  (����%d ���� )\n", expr, errCode);
	printf("���� ǥ���Ŀ��� ���� ǥ�������� ������ :" );
	infix_to_postfix(expr,arr);
	printf("%s", arr);

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


*/
