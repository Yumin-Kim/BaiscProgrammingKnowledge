#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	char* name;
	struct Node* next;
} Node;

typedef struct deque {
	Node* tail;
	Node* head;
}Deque;

void initDeque(Deque * deque) {
	deque->head = NULL;
	deque->tail = NULL;
}

void enqueue(Deque * deque , char * string) {
	if (deque->head == NULL) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->name = string;
		deque->head = newNode;
		deque->tail = newNode;
	}
	else {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->name = string;
		deque->tail->next = newNode;
		deque->tail = newNode;

	}
}

void dequeue(Deque * deque) {
	if (deque->head == NULL) {
		printf("비었습니다\n");
	}
	else {
		printf("%s\n", deque->head->name);
		deque->head = deque->head->next;
	}
}

int main(void)
{
	Deque firstDeque;
	initDeque(&firstDeque);
	enqueue(&firstDeque,"Hello");
	enqueue(&firstDeque,"World");
	enqueue(&firstDeque,"CLaguage");
	dequeue(&firstDeque);
	dequeue(&firstDeque);
	dequeue(&firstDeque);
	return 0;
}