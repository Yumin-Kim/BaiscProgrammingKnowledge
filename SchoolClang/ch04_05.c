/*
�ǽ���:���� ǥ���Ŀ��� ���� ǥ���� ������ ��� �� ���!! �ǽ�!!
������ ����: �ڿ��� ������
�ǽ���: 2020 04 18
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAXSTACK 100
#define EOS 0

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


int stack[MAXSTACK];
int top = -1;
int pop() {
	if (top < 0) {
		printf("stack empty");
		return top;
	}
	return stack[top--];
}
char push(char token) {
	if (MAXSTACK - 1 == top) {
		printf("stack full");
		return 0;
	}
	stack[++top] = token;
}

void convert(char* infit, char* postfix) {
	int cnt = 0;
	char token;
	push(EOS);
	for (int i = 0; infit[i] != 0; i++) {
		token = infit[i];
		if (isDigit(token)) {
			postfix[cnt++] = token;
		}
		else {
			if (token == ')') {
				do {
					postfix[cnt++] = pop();
				} while (postfix[cnt - 1] != '(');
					cnt--;
					continue;
			}
			while (getStackPriority(stack[top]) >= getPriority(token)) {
				postfix[cnt++] = pop();
			}
			push(token);
		}
	}
	do {
		postfix[cnt++] = pop();
	} while (postfix[cnt - 1] != EOS);
}

int isDigit(char token) {
	if ('0' <= token && token <= '9') {
		return -1;
	}
	else {
		return 0;
	}
}
int getPriority(char token) {
	switch (token)
	{
	case '(':
	case ')': return 10;
	case '*':
	case '/': return 5;
	case '+':
	case '-':return 2;
	default:
		break;
	}
}

int getStackPriority(char token) {
	switch (token)
	{
	case '(': return 1;
	case ')': return 10;
	case '*':
	case '/': return 5;
	case '+':
	case '-':return 2;
	default:
		break;
	}
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
	char c;
	int i = 0;
	double val, val1, val2;
	init_stack();
	while (expr[i] != '\0') {
		c = expr[i++];
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
	}
	return pop();
}

int main() {
	int errCode;
	char infix[20], postfix[20];
	printf("���� �Է��ϼ��� >>");
	scanf("%s", infix);
	errCode = check_matching(infix);
	if (errCode == 0) printf(" ���� : %s\n ", infix);
	else printf("���� :>> �Է� %s  (����%d ���� )\n", infix, errCode);
	convert(infix, postfix);
	printf("���� ǥ���Ŀ��� ���� ǥ���� ���� >> %s\n ", postfix);
	printf("result >> %lf\n",calc_postfix(postfix));
}




