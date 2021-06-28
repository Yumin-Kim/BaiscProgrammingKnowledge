#include <stdio.h>
#include <malloc.h>
typedef struct node {
	int nData;
	struct Node* next;
}Node;

typedef struct stack {
	Node* top;
} Stack;


int isEmpty(Stack * stack) {
	if (stack->top == NULL)
	{
		printf("Stack is empty");
		return 0;
	}else{
		return 1;
	}
}

void push(Stack * stack , int nParam) 
{
	Node* newStack = (Stack*)malloc(sizeof(Stack));
	newStack->nData = nParam;
	newStack->next = stack->top;
	stack->top = newStack;
}

void InitStack(Stack * stack){
	printf("초기화 중\n");
	stack->top = NULL;
}

int pop(Stack * stack) 
{
	Node* Copystack = stack->top;
	stack->top = Copystack->next;
	return Copystack->nData;
}

int main() {
	Stack LeftStack;
	
	InitStack(&LeftStack);
	for (int i = 0; i < 5; i++)
	{
		printf("push %d\t", i * 10);
		push(&LeftStack, i * 10);
	}
	puts("");
	while (isEmpty(&LeftStack))
	{
		printf("pop : %d\n",pop(&LeftStack));
	}
	return 0;
}