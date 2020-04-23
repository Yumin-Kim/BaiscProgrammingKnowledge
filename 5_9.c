/*
실습명: 5-9장 실습!!
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
		error("큐 공백 에러");
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
		error("큐 공백 에러");
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
	enqueue(get_student(2018130007, "홍길동", "컴퓨터 공학과"));
	enqueue(get_student(2018130100, "이순신", "기계 공학과"));
	enqueue(get_student(2018130200, "김연아", "체육교육과"));
	enqueue(get_student(2018130321, "황희", "법학과"));

	print_queue("연결된 학생 큐는(4명 삽입)");
	dequeue();
	print_queue("연결된 학생 큐는(1명 삭제)");
	destory_queue();

}












