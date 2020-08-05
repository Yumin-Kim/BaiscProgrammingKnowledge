#include <stdio.h>
#include <malloc.h>

typedef struct _node {
	int val;
	struct _node* next;
} node;



//1. 링크드 리스트의 맨뒤에 노드를 append한다.

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



//2. 링크드 리스트의 노드 순서대로 데이터를 출력한다.

void print_likedlist(node* head)

{

	while (head != NULL) {

		printf("%d=>", head->val);

		head = head->next;

	}

	printf("End\n");

}



//3. 해당 데이터(val)를 갖는 노드를 삭제한다.

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
			*head = NULL;
		}
		while (p_ChangePointer->next != NULL) {
			p_assignPointer = p_ChangePointer;
			if (p_ChangePointer->val == val)
			{
				valid = 1;
				printf("원하는 숫자를 찾았습니다 >> %d >> 삭제 되었습니다\n", p_ChangePointer->next->val);
				*p_assignPointer = *(p_ChangePointer->next);
				return;
			}
			p_ChangePointer = p_ChangePointer->next;
		}
		if (valid == 0) puts("원하는 숫자는 연결리스트에 존재 하지 않습니다");
	}
	else
		puts("연결리스트가 비었습니다");
}



//4. 링크드 리스트의 첫번째 데이터를 반환하고 노드를 삭제한다. 없으면 -1을 리턴한다.

int deque_likedlist(node** head)
{
	node* p_CheckHead = *head;
	if (*head == NULL)
	{
		printf("비어 있는 연결리스트입니다");
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



//5. 링크드 리스트의 마직막 데이터를 반환하고 노드를 삭제한다. 없으면 -1을 리턴한다.

int pop_likedlist(node** head)
{
	node* p_lastBeforeNode = NULL;
	node* p_lastNode = *head;
	if (*head == NULL) {
		printf("비어 있는 연결리스트입니다");
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



//6. 링크드 리스트의 첫번째에 노드를 삽입한다.

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
	//스위치 케이스 함수 배열로 만들기
	while (1) {
		int nListNumber = 0;
		int nInput = 0;
		puts("원하는 카테고리 선택 [1]리스트 추가 \t[2]원하는 리스트요소 제거 \t[3]처음 리스트요소 삭제\t[4]마지막 리스트 요소 삭제\t[5]리스트요소 확인\t종료시 다른번호입력");
		scanf_s("%d", &nListNumber);
		if (nListNumber < 0 || nListNumber > 5) return;
		else {
			if (nListNumber < 3)
			{
				puts("원하는 숫자를 입력 하세요");
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