/*
실습명:6_4 >> struct를 이용한 List 실습!!
교수님 성함: 박웅규 교수님
실습일: 2020 04 27
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/
#include <stdio.h>

#define MAX_LIST_SIZE 100
typedef int Elements;
typedef struct List {
	Elements data[MAX_LIST_SIZE];
	int length;
} List;

void error(char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}

void init_list(List *p) { p->length = 0; }
void clear_list(List* p) { p->length = 0; }
int is_empty(List* p) { return p->length == 0; }
int is_full(List* p) { return p->length == MAX_LIST_SIZE; }
int get_entry(List* p,int id) { return p->data[id]; }
void replace(List* p,int id, Elements e) { p->data[id] = e; }
int size(List* p) { return p->length; }

void insert(List *p,int pos, Elements e) {
	int i;
	if (is_full(p) == 0 && pos >= 0 && pos <= p->length) {
		for (i = p->length; i > pos; i--) {
			p->data[i] = p->data[i - 1];
		}
		p->data[pos] = e;
		p->length++;
	}
	else error("포화 상태 입니다!!");
}

void delete(List* p,int pos) {
	int i = 0;
	if (is_empty(p) == 0 && pos >= 0 && pos < p->length) {
		for (i = pos + 1; i < p->length; i++) {
			p->data[i - 1] = p->data[i];
		}
		p->length--;
	}
	else error("공백 상태 입니다!!");
}

int find(List* p,Elements item) {
	int i;
	for (i = 0; i < p->length; i++) {
		if (p->data[i] == item) return i;
		return -1;
	}
}

void print_list(List* p,char* msg) {
	int i;
	printf("%s[%2d]:", msg, p->length);
	for (i = 0; i < p->length; i++) {
		printf("%2d ", p->data[i]);
	}
	printf("\n");
}

int main() {
	List l1, l2;
	init_list(&l1);
	init_list(&l2);

	insert(&l1,0, 10);
	insert(&l1,0, 20);
	insert(&l1,1, 30);
	insert(&l1,size(&l1), 40);
	insert(&l1,2, 50);
	print_list(&l1,"List 1 배열로 구현한 List(삽입 X 5)");

	replace(&l1,2, 90);
	print_list(&l1,"List 1 배열로 구현한 List(교체 X 1)");

	delete(&l1,2);
	delete(&l1, size(&l1) - 1);
	delete(&l1, 0);
	print_list(&l1," List 1 배열로 구현한 List( 삭제 X 3)");

	clear_list(&l1);
	print_list(&l1, " List 1 배열로 구현한 List( 정리후)");

	insert(&l2, 0, 10);
	insert(&l2, 0, 20);
	insert(&l2, 1, 30);
	insert(&l2, size(&l2), 40);
	insert(&l2, 2, 50);
	insert(&l2, 2, 100);
	print_list(&l2, "List 2 배열로 구현한 List(삽입 X 6)");

	replace(&l2, 2, 90);
	print_list(&l2, "List 2 배열로 구현한 List(교체 X 1)");

	delete(&l2, 2);
	delete(&l2, size(&l2) - 1);
	delete(&l2, 0);
	print_list(&l2, " List 2 배열로 구현한 List( 삭제 X 3)");

	clear_list(&l2);
	print_list(&l2, " List 1 배열로 구현한 List( 정리후)");


	return 0;
}