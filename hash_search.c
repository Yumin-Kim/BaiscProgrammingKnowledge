/*
�ǽ���: Hash_Search Programing �ǽ�!!
������ ����: �ڿ��� ������
�ǽ���: 2020 06 15
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE		13

/*  ���ڿ��� �� Ž��Ű�� ���ڷ� ��ȯ : ������ ���� ���  */
int transform(char* key)
{
	int number = 0;
	while (*key != '\0') number += (*key++);
	return number;
}
/*   �ؽ� �Լ�: ���� �Լ� ���   */
int hash_function(char* key)
{
	return transform(key) % TABLE_SIZE;
}


typedef struct RecordNode {
	char key[128];			/*  Ű �ʵ� (������ ��� ���ܾ�� �ش�)   */
	char value[128];		/*   ���õ� �ڷ� (������ ��� ���ǹ̡��� �ش�)    */
	struct RecordNode* link;
} Node;
Node* ht[TABLE_SIZE];

void init_map()
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++)
		ht[i] = NULL;
}
void print_map()
{
	int i;
	Node* p;
	for (i = 0; i < TABLE_SIZE; i++) {
		printf("[%2d] ", i);
		for (p = ht[i]; p != NULL; p = p->link)
			printf("%10s", p->key);
		printf("\n");
	}
}
void add_record(char* key, char* val)
{
	Node* p;

	int hashValue = hash_function(key);
	for (p = ht[hashValue]; p != NULL; p = p->link) {
		if (strcmp(p->key, key) == 0) {
			printf("�̹� Ž��Ű�� ����Ǿ� ����\n");
			return;
		}
	}
	p = (Node*)malloc(sizeof(Node));
	strcpy(p->key, key);
	strcpy(p->value, val);
	p->link = ht[hashValue];
	ht[hashValue] = p;
}
void search_record(char* key)
{
	Node* p;

	int hashValue = hash_function(key);
	for (p = ht[hashValue]; p != NULL; p = p->link) {
		if (strcmp(p->key, key) == 0) {
			printf("[%8s] Ž������", key);
			printf("[%2d] %20s = %s\n", hashValue, p->key, p->value);
			return;
		}
	}
	printf("[%8s] Ž�� ����: ã�� ���� ���̺� ����\n", key);
}

/*  main function  */
int  main(void)
{
	init_map();
	add_record("do", "�ݺ�");
	add_record("for", "�ݺ�");
	add_record("if", "�б�");
	add_record("case", "�б�");
	add_record("else", "�б�");
	add_record("return", "��ȯ");
	add_record("function", "�Լ�");
	print_map();
	search_record("return");
	search_record("function");
	search_record("class");

	return 0;
}

