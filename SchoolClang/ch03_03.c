/*
�ǽ���:strcmp strcat strlen �ǽ� ����
������ ����: �ڿ��� ������
�ǽ���: 2020 04 01
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/
#include <stdio.h>
#include <string.h>

void main() {

	char s1[40] = "C language is";
	char s2[40] = "a good programming language";
	char s3[20];
	int length;

	length = strlen(s1);
	printf("String length is %d \n", length);
	strcpy(s3, s1);
	printf("s3 = %s \n", s3);
	if (strcmp(s1, s3) == 0) printf("s1 is equal to s3 ");
	else printf("s1 is not equal to s3 \n");
	if (strcmp(s1, s2) == 0)printf("s1 is node equal to s2 \n");
	else printf("s1 is not equal to s2 \n");

	strcat(s1, s2);
	printf("s1 = %s \n", s1);

}