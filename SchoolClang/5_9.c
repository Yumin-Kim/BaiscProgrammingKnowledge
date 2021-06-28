/*
�ǽ���: 5-9�� �ǽ�!!
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


Node* front = NULL;
Node* rear = NULL;

Node error(char str[]) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}

int is_empty() {
	return front == NULL;
}

void init_queue() {
	front = rear = NULL;
}

int size() {
	Node* p;
	int count = 0;
	for (p = front; p != NULL; p = p->link) count++;
	return count;
}

void enqueue(Elements e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->link = NULL;

	if (is_empty()) front = rear = p;
	else
	{
		rear->link = p;
		rear = p;
	}

}

Elements dequeue() {
	Node* p;
	Elements e;

	if (is_empty()) {
		error("ť ���� ����");
	}

	p = front;
	front = front->link;
	if (front == NULL) rear = NULL;
	e = p->data;
	free(p);
	return e;
}

Elements peek() {
	if (is_empty()) {
		error("ť ���� ����");
	}
	return front->data;
}

void destory_queue() {
	while (is_empty() == 0) {
		dequeue();
	}
}

void print_queue(char msg[]) {
	Node* p;
	printf("%s[%2d] = ",msg , size());
	for (p = front; p != NULL; p = p->link) {
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
	init_queue();
	enqueue(get_student(2018130007, "ȫ�浿", "��ǻ�� ���а�"));
	enqueue(get_student(2018130100, "�̼���", "��� ���а�"));
	enqueue(get_student(2018130200, "�迬��", "ü��������"));
	enqueue(get_student(2018130321, "Ȳ��", "���а�"));

	print_queue("����� �л� ť��(4�� ����)");
	dequeue();
	print_queue("����� �л� ť��(1�� ����)");
	destory_queue();

}












