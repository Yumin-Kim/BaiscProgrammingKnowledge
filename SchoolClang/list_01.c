/*
�ǽ���:6_4�ǽ�!!
������ ����: �ڿ��� ������
�ǽ���: 2020 04 27
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
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
	else error("��ȭ ���� �Դϴ�!!");
}

void delete(int pos) {
	int i = 0;
	if (is_empty()==0 && pos >= 0 && pos < length) {
		for (i = pos + 1; i < length; i++) {
			data[i - 1] = data[i];
		}
		length--;
	}
	else error("���� ���� �Դϴ�!!");
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
	print_list("�迭�� ������ List(���� X 5)");

	replace(2, 90);
	print_list("�迭�� ������ List(��ü X 1)");

	delete(2);
	delete(size() - 1);
	delete(0);
	print_list("�迭�� ������ List( ���� X 3)");



	return 0;
}