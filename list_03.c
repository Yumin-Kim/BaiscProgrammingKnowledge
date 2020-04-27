/*
실습명:6_13 실습!!
교수님 성함: 박웅규 교수님
실습일: 2020 04 27
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/
#include <stdio.h>
#include <stdlib.h>
typedef int Elements;
typedef struct LinkedNode {
	Elements data;
	struct LinkedNode* link;
} Node;

Node* head = NULL;

void error(char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}

void init_list() { head = NULL; }

int is_empty() { return head == NULL; }
Node* get_entry(int pos) {
	Node* p = head;
	int i;
	for (i = 0; i < pos; p = p->link) {
		if (p == NULL) return NULL;
		return p;
	}
}
void replace(int pos, Elements e) {
	Node* node = get_entry(pos);
	if (node != NULL) {
		node->data = e;
	}
}
int size() {
	Node* p;
	int count = 0;
	for (p = head; p != NULL; p = p->link)
		count++;
	return count;
}

void insert_next(Node* before, Node *node) {
	if (node != NULL) {
		node->link = before->link;
		before->link = node;
	}
}

void insert(int pos , Elements e) {
	Node* new_node, * prev;

	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = e;
	new_node->link = NULL;
	
	if (pos == 0) {
		new_node->link = head;
		head = new_node;
	}
	else if(pos > 0) {
		prev = get_entry(pos - 1);
		if (prev != NULL) {
			insert_next(prev, new_node);
		}
		else {
			free(new_node);
		}
	}
	else {
		free(new_node);
		error("inserted position is error");
	}
}

Node* remove_next(Node* before) {
	Node* remove = before->link;
	if (remove != NULL) before->link = remove->link;
	return remove;
}

void delete(int pos) {
	Node* prev, * remove;
	if (pos == 0 && is_empty() == 0) {
		remove = head;
		head = head->link;
		free(remove);
	}
	else if(pos > 0)  {
		prev = get_entry(pos - 1);
		if (prev != NULL) {
			remove = remove_next(prev);
			free(remove);
		}
		else{
			error("Deleted position is error");
		}
	}
	else {
		error("Deleted position is error");
	}
}

Node* find(Elements val) {
	Node* p;
	for (p = head; p != NULL; p = p->link)
		if (p->data = val) return p;
	return NULL;
}

void print_list(char* msg) {
	Node* p;
	printf("%s[%2d] : ",msg, size());
	for (p = head; p != NULL; p = p->link) {
		printf("%2d ", p->data);
	}
	printf("\n");
}
void clear_list() {
	while (is_empty() == 0) {
		delete(0);
	}
}
int main() {
	init_list();
	insert(0, 10);
	insert(0, 20);
	insert(1, 30);
	insert(size(), 40);
	insert(2, 50);
	print_list("단순한 연결 리스트 구현 한 LIST(삽입 X 5)");

	replace(2, 90);
	print_list("단순한 연결 리스트 구현 한 LIST(교체 X 1)");

	delete(2);
	delete(size()-1);
	delete(0);
	print_list("단순한 연결 리스트 구현 한 LIST(삭제 X 3)");

	clear_list();
	print_list("단순한 연결 리스트 구현 한 LIST(정리후)");

	return 0;
}