/*
실습명: 5-9장 Programing 실습!!
교수님 성함: 박웅규 교수님
실습일: 2020 04 21
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
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
		error("큐 공백 에러");
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
		error("큐 공백 에러");
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

	enqueue(&q1,get_student(2018130007, "홍길동", "컴퓨터 공학과"));
	enqueue(&q1,get_student(2018130100, "이순신", "기계 공학과"));
	enqueue(&q1,get_student(2018130200, "김연아", "체육교육과"));
	enqueue(&q1,get_student(2018130321, "황희", "법학과"));

	print_queue(&q1,"queue 1 연결된 학생 큐는(4명 삽입)");
	dequeue(&q1);
	print_queue(&q1,"queue 1 연결된 학생 큐는(1명 삭제)");
	enqueue(&q2,get_student(2012130007, "홍길동", "컴퓨터 공학과"));
	enqueue(&q2,get_student(2012130100, "이순신", "기계 공학과"));
	enqueue(&q2,get_student(2012130200, "김연아", "체육교육과"));
	enqueue(&q2,get_student(2012130321, "황희", "법학과"));
	enqueue(&q2,get_student(2012130321, "황희", "법학과"));

	print_queue(&q2,"queue 2 연결된 학생 큐는(5명 삽입)");
	dequeue(&q2);
	print_queue(&q2,"queue 2 연결된 학생 큐는(1명 삭제)");
	destory_queue(&q1);
	destory_queue(&q2);

}