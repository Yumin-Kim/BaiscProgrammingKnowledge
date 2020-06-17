/*
�ǽ���:Meeting ť �ǽ�
������ ����: �ڿ��� ������
�ǽ���: 2020 04 13
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 100

typedef struct Meeting_S {
	char name[20];
	char s[2];
}Meeting;

typedef Meeting Elements;

typedef struct CirularQueue{
	Elements data[MAX_QUEUE_SIZE];
	int front;
	int rear;
} Queue;

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

void init_queue(Queue* q) { q->front = q->rear = 0; ; }
int is_empty(Queue* q) {
	return q->front == q->rear;
}
int is_full(Queue* q) {
	return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

int size(Queue* q) {
	return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void enqueue(Queue* q, Elements val) {
	if (is_full(q)) {
		error("ť ��ȭ ����");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = val;
}

Elements dequeue(Queue* q) {
	if (is_empty(q)) {
		error(" ť ���� ���� ");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

Elements peek(Queue* q) {
	if (is_empty(q)) {
		error("ť ���� ����");
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void print_queue(Queue* q, char msg[]) {
	int i, maxi = q->rear;
	if (q->front >= q->rear) maxi += MAX_QUEUE_SIZE;
	printf("%s[%2d]= ", msg, size(q));
	for (i = q->front + 1; i <= maxi; i++) {
		printf("%2d", q->data[i % MAX_QUEUE_SIZE]);
	}
	printf("\n");
}

void main() {
	Queue boy, girl;
	Elements p, q;
	
	init_queue(&boy);
	init_queue(&girl);
	printf("���� �ּ� ���α׷� �Դϴ� \n\n");

	while (1) {
		printf("���� �̸��� (���� -1) >>");
		scanf("%s",&p.name);
		if (strcmp(p.name, "-1") == 0) break;
		else {
			printf("������ �Է� (���ڴ� boy , ���ڴ�  girl) >>");
			scanf("%s", &p.s);
			if (strcmp(p.s, "f") == 0) {
				if (is_empty(&boy)) {
					printf("������ ����ڰ� �����ϴ� \n");
					enqueue(&girl, p);
				}
				else {
					q = dequeue(&boy);
					printf("Ŀ�� ź�� %s �� %s  \n\n",q.name , p.name);

				}
			}
			else if (strcmp(p.s, "m") == 0) {
				if (is_empty(&girl)) {
					printf("������ ����ڰ� �����ϴ� \n");
					enqueue(&boy, p);
				}
				else {
					q = dequeue(&girl);
					printf("Ŀ�� ź�� %s �� %s  \n\n", p.name, q.name);

				}
			}
			else {
				printf("�߸��� �Է� �Դϴ�\n");
			}
		}/*end of if*/
	}/*end of while*/

	printf("\n\n���� �ּ� ���α׷��� �����մϴ�");


}


