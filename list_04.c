/*
실습명:6_17 실습!!
교수님 성함: 박웅규 교수님
실습일: 2020 04 27
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR_PER_LINE 1000

typedef struct Line {
	char str[MAX_CHAR_PER_LINE];
}Line;
typedef Line Elements;
typedef struct LinkedNode {
	Elements data;
	struct LinkedNode* link;
} Node;

Node* head;

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

void insert_next(Node* before, Node* node) {
	if (node != NULL) {
		node->link = before->link;
		before->link = node;
	}
}

void insert(int pos, Elements e) {
	Node* new_node, * prev;

	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = e;
	new_node->link = NULL;

	if (pos == 0) {
		new_node->link = head;
		head = new_node;
	}
	else if (pos > 0) {
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
	else if (pos > 0) {
		prev = get_entry(pos - 1);
		if (prev != NULL) {
			remove = remove_next(prev);
			free(remove);
		}
		else {
			error("Deleted position is error");
		}
	}
	else {
		error("Deleted position is error");
	}
}

void print_list(char* msg) {
	Node* p;
	printf("%s[%2d] : ", msg, size());
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

void display(FILE* fp) {
	int i = 0;
	Node* p;
	for (p = head; p != NULL; p = p->link, i++) {
		fprintf(stderr, "%3d : ", i);
		fprintf(fp, "%s", p->data.str);
	}
}

void my_fflush() { while (getchar() != '\n'); }

int main() {

	char command;
	int pos;
	Line line;
	FILE* fp;

	init_list();
	do {
		printf("[메뉴 선택] i>> 입력, d >> 삭제 , r>> 변경 , p >> 출력 , l>> 파일 읽기 , s >> 저장 q >> 종료 >>");
		command = getchar();
		switch (command)
		{
		case'i':
			printf(" 입력 번호 : ");
			scanf("%d", &pos);
			printf(" 입력 내용 : ");
			my_fflush();
			fgets(line.str, MAX_CHAR_PER_LINE, stdin);
			insert(pos, line);
			break;
		case'd':
			printf(" 삭제 행 번호 : ");
			scanf("%d", &pos);
			delete(pos);
			break;
		case'r':
			printf(" 삭제 행 번호 : ");
			scanf("%d", &pos);
			printf(" 변경 행 번호 ");
			my_fflush();
			fgets(line.str, MAX_CHAR_PER_LINE, stdin);
			replace(pos, line);
			break;
		case'l':
			fp = fopen("Text.txt", "r");
			if (fp != NULL) {
				while (fgets(line.str, MAX_CHAR_PER_LINE, fp))
					insert(size(), line);
				fclose(fp);
			}
			break;
		case's':
			fp = fopen("Text.txt", "w");
			if (fp != NULL) {
				display(fp);
				fclose(fp);
			}
		case'p': display(stdout);

		}
		my_fflush();
	} while (command != 'q');



	return 0;
}