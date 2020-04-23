/*
�ǽ���: 5-9�� Programing �ǽ�!!
������ ����: �ڿ��� ������
�ǽ���: 2020 04 21
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	int id;
	char name[32];
	char dept[32];
}Student;

typedef Student Elements;

typedef struct LinkedNode {
	Elements data;
	struct LinkendNode* link;
} Node;

typedef struct linkedqueue {
	Node* front;
	Node* rear;
}Linkedqueue;

Node error(char str[]) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}

int is_empty(Linkedqueue *p) {
	return p->front== NULL;
}

void init_queue(Linkedqueue *p) {
	p->front = p->rear = NULL;
}

int size(Linkedqueue *q) {
	Node* p;
	int count = 0;
	for (p = q->front; p != NULL; p = p->link) count++;
	return count;
}

void enqueue(Linkedqueue *q,Elements e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->link = NULL;

	if (is_empty(q)) q->front = q->rear = p;
	else
	{
		q->rear->link = p;
		q->rear = p;
	}

}

Elements dequeue(Linkedqueue *q) {
	Node* p;
	Elements e;

	if (is_empty(q)) {
		error("ť ���� ����");
	}

	p = q->front;
	q->front = q->front->link;
	if (q->front == NULL) q->rear = NULL;
	e = p->data;
	free(p);
	return e;
}

Elements peek(Linkedqueue *q) {
	if (is_empty(q)) {
		error("ť ���� ����");
	}
	return q->front->data;
}

void destory_queue(Linkedqueue *q) {
	while (is_empty(q) == 0) {
		dequeue(q);
	}
}

void print_queue(Linkedqueue *q,char msg[]) {
	Node* p;
	printf("%s[%2d] = ", msg, size(q));
	for (p = q->front; p != NULL; p = p->link) {
		printf("\n\t%-15d %-10s %-20s", p->data.id, p->data.name, p->data.dept);
	}
	printf("\n");
}

Student get_student(int id, char* name, char* dept) {
	Student s;
	s.id = id;
	strcpy(s.name, name);
	strcpy(s.dept, dept);
	return s;
}

void main() {
	Linkedqueue q1, q2;
	init_queue(&q1);
	init_queue(&q2);

	enqueue(&q1,get_student(2018130007, "ȫ�浿", "��ǻ�� ���а�"));
	enqueue(&q1,get_student(2018130100, "�̼���", "��� ���а�"));
	enqueue(&q1,get_student(2018130200, "�迬��", "ü��������"));
	enqueue(&q1,get_student(2018130321, "Ȳ��", "���а�"));

	print_queue(&q1,"queue 1 ����� �л� ť��(4�� ����)");
	dequeue(&q1);
	print_queue(&q1,"queue 1 ����� �л� ť��(1�� ����)");
	enqueue(&q2,get_student(2012130007, "ȫ�浿", "��ǻ�� ���а�"));
	enqueue(&q2,get_student(2012130100, "�̼���", "��� ���а�"));
	enqueue(&q2,get_student(2012130200, "�迬��", "ü��������"));
	enqueue(&q2,get_student(2012130321, "Ȳ��", "���а�"));
	enqueue(&q2,get_student(2012130321, "Ȳ��", "���а�"));

	print_queue(&q2,"queue 2 ����� �л� ť��(5�� ����)");
	dequeue(&q2);
	print_queue(&q2,"queue 2 ����� �л� ť��(1�� ����)");
	destory_queue(&q1);
	destory_queue(&q2);

}