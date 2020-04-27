/*
실습명:6_4실습!!
교수님 성함: 박웅규 교수님
실습일: 2020 04 27
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/
#include <stdio.h>

#define MAX_LIST_SIZE 100
typedef int Elements;
Elements data[MAX_LIST_SIZE];
int length = 0;

void error(char *str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}

void init_list() { length = 0; }
void clear_list() { length = 0; }
int is_empty() { return length == 0; }
int is_full() { return length == MAX_LIST_SIZE; }
int get_entry(int id) { return data[id]; }
void replace(int id, Elements e) { data[id] = e; }
int size() { return length; }

void insert(int pos, Elements e) {
	int i;
	if (is_full()==0 && pos >= 0 && pos <= length) {
		for (i = length; i > pos; i--) {
			data[i] = data[i - 1];
		}
		data[pos] = e;
		length++;
	}
	else error("포화 상태 입니다!!");
}

void delete(int pos) {
	int i = 0;
	if (is_empty()==0 && pos >= 0 && pos < length) {
		for (i = pos + 1; i < length; i++) {
			data[i - 1] = data[i];
		}
		length--;
	}
	else error("공백 상태 입니다!!");
}

int find(Elements item) {
	int i;
	for (i = 0; i < length; i++) {
		if (data[i] == item) return i;
		return -1;
	}
}

void print_list(char * msg) {
	int i;
	printf("%s[%2d]:", msg, length);
	for (i = 0; i < length; i++) {
		printf("%2d ", data[i]);
	}
	printf("\n");
}

int main() {
	init_list();

	insert(0, 10);
	insert(0, 20);
	insert(1, 30);
	insert(size(), 40);
	insert(2, 50);
	print_list("배열로 구현한 List(삽입 X 5)");

	replace(2, 90);
	print_list("배열로 구현한 List(교체 X 1)");

	delete(2);
	delete(size() - 1);
	delete(0);
	print_list("배열로 구현한 List( 삭제 X 3)");



	return 0;
}