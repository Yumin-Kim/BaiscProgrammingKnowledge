#include <stdio.h>
#include <malloc.h>

typedef struct _node {
	int val;
	struct _node* next;
} node;



//1. ��ũ�� ����Ʈ�� �ǵڿ� ��带 append�Ѵ�.

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



//2. ��ũ�� ����Ʈ�� ��� ������� �����͸� ����Ѵ�.

void print_likedlist(node* head)

{

	while (head != NULL) {

		printf("%d=>", head->val);

		head = head->next;

	}

	printf("End\n");

}



//3. �ش� ������(val)�� ���� ��带 �����Ѵ�.

void del_likedlist(node** head, int val)
{
	node* p_ChangePointer = *head;
	node* p_assignPointer = NULL;
	int valid = 0;
	if (*head != NULL)
	{
		if ((*head)->next == NULL) {
			valid = 1;
			printf("���ϴ� ���ڸ� ã�ҽ��ϴ� >> %d >> ���� �Ǿ����ϴ�\n", (*head)->val);
			*head = NULL;
		}
		while (p_ChangePointer->next != NULL) {
			p_assignPointer = p_ChangePointer;
			if (p_ChangePointer->val == val)
			{
				valid = 1;
				printf("���ϴ� ���ڸ� ã�ҽ��ϴ� >> %d >> ���� �Ǿ����ϴ�\n", p_ChangePointer->next->val);
				*p_assignPointer = *(p_ChangePointer->next);
				return;
			}
			p_ChangePointer = p_ChangePointer->next;
		}
		if (valid == 0) puts("���ϴ� ���ڴ� ���Ḯ��Ʈ�� ���� ���� �ʽ��ϴ�");
	}
	else
		puts("���Ḯ��Ʈ�� ������ϴ�");
}



//4. ��ũ�� ����Ʈ�� ù��° �����͸� ��ȯ�ϰ� ��带 �����Ѵ�. ������ -1�� �����Ѵ�.

int deque_likedlist(node** head)
{
	node* p_CheckHead = *head;
	if (*head == NULL)
	{
		printf("��� �ִ� ���Ḯ��Ʈ�Դϴ�");
		return -1;
	}
	if (p_CheckHead->next == NULL)
	{
		*head = NULL;
		return -1;
	}
	else
	{
		*p_CheckHead = *(p_CheckHead->next);
		return 0;
	}
}



//5. ��ũ�� ����Ʈ�� ������ �����͸� ��ȯ�ϰ� ��带 �����Ѵ�. ������ -1�� �����Ѵ�.

int pop_likedlist(node** head)
{
	node* p_lastBeforeNode = NULL;
	node* p_lastNode = *head;
	if (*head == NULL) {
		printf("��� �ִ� ���Ḯ��Ʈ�Դϴ�");
		return -1;
	}
	while (p_lastNode->next != NULL) {
		p_lastBeforeNode = p_lastNode;
		p_lastNode = p_lastNode->next;
	}
	if (p_lastBeforeNode == NULL) {
		*head = NULL;
		return -1;
	}
	else {
		p_lastBeforeNode->next = NULL;
		return 0;
	}
}



//6. ��ũ�� ����Ʈ�� ù��°�� ��带 �����Ѵ�.

int push_likedlist(node** head, int val)

{
	node* NewNode = (node*)malloc(sizeof(node));
	NewNode->val = val;
	NewNode->next = *head;
	*head = NewNode;
	return 0;
}



node* my_head = NULL;



int main()
{
	void* (*p_AddDeleteList[2])(node**, int) = {
		enque_likedlist,
		del_likedlist
	};
	int* (*p_PushPopList[2])(node**) = {
		push_likedlist,
		pop_likedlist,
	};
	//����ġ ���̽� �Լ� �迭�� �����
	while (1) {
		int nListNumber = 0;
		int nInput = 0;
		puts("���ϴ� ī�װ� ���� [1]����Ʈ �߰� \t[2]���ϴ� ����Ʈ��� ���� \t[3]ó�� ����Ʈ��� ����\t[4]������ ����Ʈ ��� ����\t[5]����Ʈ��� Ȯ��\t����� �ٸ���ȣ�Է�");
		scanf_s("%d", &nListNumber);
		if (nListNumber < 0 || nListNumber > 5) return;
		else {
			if (nListNumber < 3)
			{
				puts("���ϴ� ���ڸ� �Է� �ϼ���");
				scanf_s("%d", &nInput);
				p_AddDeleteList[nListNumber - 1](&my_head, nInput);
			}
			else if (nListNumber == 5)
				print_likedlist(my_head);
			else
			{
				p_PushPopList[nListNumber - 3](&my_head);
			}
		}
	}
	return 0;

}