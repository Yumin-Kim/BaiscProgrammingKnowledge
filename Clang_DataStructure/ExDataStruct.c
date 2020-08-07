#include <stdio.h>
#include <malloc.h>

extern struct node;
extern struct node* my_head;

//1. ��ũ�� ����Ʈ�� �ǵڿ� ��带 append�Ѵ�.
void enque_likedlist(struct node** head, int val);
//2. ��ũ�� ����Ʈ�� ��� ������� �����͸� ����Ѵ�.
void print_likedlist(struct node* head);
//3. �ش� ������(val)�� ���� ��带 �����Ѵ�.
void del_likedlist(struct node** head, int val);
//4. ��ũ�� ����Ʈ�� ù��° �����͸� ��ȯ�ϰ� ��带 �����Ѵ�. ������ -1�� �����Ѵ�.
int deque_likedlist(struct node** head);
//5. ��ũ�� ����Ʈ�� ������ �����͸� ��ȯ�ϰ� ��带 �����Ѵ�. ������ -1�� �����Ѵ�.
int pop_likedlist(struct node** head);
//6. ��ũ�� ����Ʈ�� ù��°�� ��带 �����Ѵ�.
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
	//����ġ ���̽� �Լ� �迭�� �����
	while (1) {
		int nListNumber = 0;
		int nInput = 0;
		puts("���ϴ� ī�װ� ����\n [1]����Ʈ �߰�(��) \t[2]����Ʈ �߰�(��) \t[3]���ϴ� ����Ʈ��� ���� \t[4]ó�� ����Ʈ��� ����\t[5]������ ����Ʈ ��� ����\t[6]����Ʈ��� Ȯ��\t����� �ٸ���ȣ�Է�");
		scanf_s("%d", &nListNumber);
		if (nListNumber < 0 || nListNumber > 6) return;
		else {
			if (nListNumber < 4)
			{
				puts("���ϴ� ���ڸ� �Է� �ϼ���");
				scanf_s("%d", &nInput);
				p_AddDeleteList[nListNumber - 1](&my_head, nInput);
			}
			else if (nListNumber == 6)
				print_likedlist(my_head);
			else
			{
				printf("���� ����� ���Դϴ� : %d\n", p_PushPopList[nListNumber - 4](&my_head));
			}
		}
	}
	return 0;

}
