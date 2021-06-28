#include <stdio.h>
#include <malloc.h>

typedef struct node {
	int val;
	struct node* next;
} node;

node* my_head = NULL;


void enque_likedlist(node** head, int val)
{
	node* p = *head;
	if (p == NULL) {
		p = (node*)malloc(sizeof(node));
		p->val = val;
		p->next = NULL;
		*head = p;
		return;
	}
	//goto the end of list
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = (node*)malloc(sizeof(node));
	p = p->next;
	p->val = val;
	p->next = NULL;
}


void print_likedlist(node* head)
{
	while (head != NULL) {
		printf("%d=>", head->val);
		head = head->next;
	}
	printf("End\n");
}

void del_likedlist(node** head, int val)
{
	node* p_ChangePointer = *head;
	node* p_assignPointer = NULL;
	int valid = 0;
	if (*head != NULL)
	{
		if ((*head)->next == NULL) {
			valid = 1;
			printf("원하는 숫자를 찾았습니다 >> %d >> 삭제 되었습니다\n", (*head)->val);
			deque_likedlist(head);
		}
		while (p_ChangePointer->next != NULL) {
			p_assignPointer = p_ChangePointer;
			if (p_ChangePointer->val == val)
			{
				valid = 1;
				printf("원하는 숫자를 찾았습니다 >> %d >> 삭제 되었습니다\n", p_ChangePointer->val);
				*p_assignPointer = *(p_ChangePointer->next);
				return;
			}
			p_ChangePointer = p_ChangePointer->next;
		}
		if (p_ChangePointer->val == val)
		{
			printf("원하는 숫자를 찾았습니다 >> %d >> 삭제 되었습니다\n", p_ChangePointer->val);
			p_assignPointer->next = NULL;
		}
		else {
			if (valid == 0) puts("원하는 숫자는 연결리스트에 존재 하지 않습니다");
		}
	}
	else
		puts("연결리스트가 비었습니다");
}
int deque_likedlist(node** head)
{
	node* p_CheckHead = *head;
	int nData = 0;
	if (*head == NULL)
	{
		printf("비어 있는 연결리스트입니다");
		return -1;
	}
	nData = (*head)->val;
	printf("%d\n", (*head)->val);
	if (p_CheckHead->next == NULL)
	{
		*head = NULL;
		return nData;
	}
	else
	{
		*head = (*head)->next;
		return nData;
	}
}

int pop_likedlist(node** head)
{
	node* p_lastBeforeNode = NULL;
	node* p_lastNode = *head;
	int nData;
	if (*head == NULL) {
		printf("비어 있는 연결리스트입니다");
		return -1;
	}
	while (p_lastNode->next != NULL) {
		p_lastBeforeNode = p_lastNode;
		p_lastNode = p_lastNode->next;
	}
	if (p_lastBeforeNode == NULL) {
		nData = p_lastBeforeNode->val;
		*head = NULL;
		return nData;
	}
	else {
		nData = p_lastBeforeNode->val;
		p_lastBeforeNode->next = NULL;
		return nData;
	}
}

void push_likedlist(node** head, int val)
{
	node* NewNode = (node*)malloc(sizeof(node));
	NewNode->val = val;
	NewNode->next = *head;
	*head = NewNode;
}