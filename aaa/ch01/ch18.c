#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	��ȣ���� �߿伺!!�� CallBack����!! ���� ���α׷����� �ַ� ���ȴ�!!
	��ȣ���� ���� ȣ���ϴ°��� �ƴϰ� �ڵ����� ȣ��Ǵ� ���̴�!!
	�帧�� �߰��� �Ⱥ��̱� ������ �����ϴ°��� ����!!

	�Լ� ������ + lookupTable�� ���� ����ϰԵǸ� switch ... case�� �Ϻ��ϰ� ������ �� �ִ�

	�ؿ���  qsort�Լ��� �� callback������ �����������??
	�پ��� �ڷ����� �����ϱ� ���ؼ� callback������ �������!!(�� ����� �޶� �� �� �ֱ� ������)
	

*/

int TestFunc(char* nParam) {
	return 100;
}

void MyTest(int(*pnFunc)(char*), int nParam) {

}

int Swap_Dev(const void* left, const void* right) {
	return *(int*)left - *(int*)right;
}


int Swap_Dev_char(const void* left, const void* right) {
	return strcmp(*	(char**)left, *(char**)right);
}

void TestFunc_1(int nParam) {
	puts("Hello_1");
}

void TestFunc_2(int nParam) {
	puts("Hello_2");
}

void TestFunc_3(int nParam) {
	puts("Hello_3");
}
int main(void)
{
	//�Լ� ��ȣ���� ����!!
	//���ڹ迭
	int aList[5] = { 20,30,40,50,10 };
	qsort(aList, 5, sizeof(int), Swap_Dev);
	for (int i = 0; i < 5; i++)
		printf("%d\t", aList[i]);
	//�̷������� �Ű� ������ �Լ��� ���� �� �� �ִ� �� ����� �Լ� �̸� ���� �޸� �ּ��� ������ �ִٴ� ���� �� �� �ִ�!!
	puts("");
	//���ڹ迭
	char* pNameTable[5] = {
		"����",
		"����",
		"ȣ��",
		"�Ҿƹ���",
		"������"
	};
	qsort(pNameTable, 5, sizeof(int),Swap_Dev_char);
	for (int i = 0; i < 5; i++)
		printf("%s\t", pNameTable[i]);
	putchar('\n');


	//�Լ� �����Ϳ� lookuptalbe
	//�迭�ȿ� �Լ��� ��´�
	int userSelectNum = 0;
	void(*pszFuncList[3])(int)  = {
		TestFunc_1,
		TestFunc_2,
		TestFunc_3
	};
	printf("���ڸ� �Է��ϼ��� : 0-3\n");
	scanf_s("%d", &userSelectNum);
	pszFuncList[userSelectNum](10);



	MyTest(TestFunc, 100);
}