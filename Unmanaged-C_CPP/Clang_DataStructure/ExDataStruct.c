#include <stdio.h>
#include <malloc.h>

extern struct node;
extern struct node* my_head;

//1. 링크드 리스트의 맨뒤에 노드를 append한다.
void enque_likedlist(struct node** head, int val);
//2. 링크드 리스트의 노드 순서대로 데이터를 출력한다.
void print_likedlist(struct node* head);
//3. 해당 데이터(val)를 갖는 노드를 삭제한다.
void del_likedlist(struct node** head, int val);
//4. 링크드 리스트의 첫번째 데이터를 반환하고 노드를 삭제한다. 없으면 -1을 리턴한다.
int deque_likedlist(struct node** head);
//5. 링크드 리스트의 마직막 데이터를 반환하고 노드를 삭제한다. 없으면 -1을 리턴한다.
int pop_likedlist(struct node** head);
//6. 링크드 리스트의 첫번째에 노드를 삽입한다.
void push_likedlist(struct node** head, int val);




int main()
{
	void (*p_AddDeleteList[3])(struct node**, int) = {
		enque_likedlist,
		push_likedlist,
		del_likedlist,
	};
	int (*p_PushPopList[2])(struct node**) = {
		deque_likedlist,
		pop_likedlist,
	};
	//스위치 케이스 함수 배열로 만들기
	while (1) {
		int nListNumber = 0;
		int nInput = 0;
		puts("원하는 카테고리 선택\n [1]리스트 추가(뒤) \t[2]리스트 추가(앞) \t[3]원하는 리스트요소 제거 \t[4]처음 리스트요소 삭제\t[5]마지막 리스트 요소 삭제\t[6]리스트요소 확인\t종료시 다른번호입력");
		scanf_s("%d", &nListNumber);
		if (nListNumber < 0 || nListNumber > 6) return;
		else {
			if (nListNumber < 4)
			{
				puts("원하는 숫자를 입력 하세요");
				scanf_s("%d", &nInput);
				p_AddDeleteList[nListNumber - 1](&my_head, nInput);
			}
			else if (nListNumber == 6)
				print_likedlist(my_head);
			else
			{
				printf("삭제 요소의 값입니다 : %d\n", p_PushPopList[nListNumber - 4](&my_head));
			}
		}
	}
	return 0;

}
