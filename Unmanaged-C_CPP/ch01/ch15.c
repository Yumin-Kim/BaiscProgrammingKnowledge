/*
����� ���� �� ����
������ ������ ���Ƕ��� �־�� �Ѵ�
������ ���� , ����� ����(���������� �ϸ� ������ Ÿ�ӿ��� �߿��ϴ�)
������ ���� , ����� ����(��ũ Ÿ�ӿ��� �߿��ϸ� �߸� ������ ��ũ Ÿ�ӿ� ������ ����)

���Ǵ� ������ ����κ��� ������ ������ ������ �߻� (extern����)
������ �ߴµ� ���� ���� ������ Link������ �߻��ϰ� �ȴ�!!

.c�� �뵵�� ������ �뵵!! >> ������ �Ŀ��� .obj����� ���� ���� �ڵ� ���� ���Ŀ� exe�� ����� ������ Link�Ѵٶ�� �Ѵ�!!
.h�� �뵵�� ������ �뵵!!

���� ������ �����Ͽ� ���α׷��� �ۼ��ߴ�
TestFunc()��� �Լ��� ������ ������ Test.c
TestFunc()��� �Լ��� ������ ������ ch15.c

�� �������� ��� ���� ���� ���ϱ�??
ch15.c,Test.c ������ �Ǹ� .obj�� Ȯ���ڸ� ������ �������� �̷������ 
���� ���� �����ϵ� ������  .obj�� ���� ó�� �κп� Export table�� �ִ�
Test.obj ������ table(Symbol table)�ȿ�  TestFunc()�� ���� �Ǿ� �ִٴ� ������ ��� �ִ�
link�۾��� ���� .exe ������ �����ϴµ� �����ϱ� ���ؼ��� obj ������ ��ġ�Եȴ�!!
��ġ�� �������� TestFunc��� �κ��� ����Ǿ� �ְ� call�ϴ� �κ�(�Լ� ȣ��)���� Test.obj�� ���̺��� ������ ���� �κ��� ã�Ƽ� �ӹ��� �����ϰ� �ȴ�!!
�����ϸ� linktime(obj ������ ��ġ�� ����)�Ҷ� main�Լ��� �������� ����ǰ� �Ǵµ� TestFunc call(TestFuncȣ��)�� ������ �Ǹ� Test���Ϸ� �Ѿ TestFunc�� �����ϰԵǰ� ������ ������ �ٽ� main �Լ��� ���ư� ���α׷��� ����ǰ� �ȴ�!!
Linktime���� �߿��� ���� ������ ���ǰ� ��� �ִ����� ã�� ������ �Ѵ�!!

���� Testfunc��� �Լ��� ������ �ϰ� �Ǹ� ������ Ÿ�ӿ��� ������ �����ʰ� LinkŸ�Կ��� ������ ���� ����� ���� �ִ�(���� ������ .obj���� �߻�!!)
���� �ϸ� �������� ���赵�� ���� ��ǰ�� �����ϴ� �����̰� Link�� �����ϴ� �����̸� 
Test.c , ch15.c , TestPrint.c �� ��ǰȭ�ϴµ��� ������ ������ Link�� �����ϴ� �������� ��ǰ�� �ΰ����� Link������ �߻��ϰ� �ȴ�!!

/////////////////////
������ ���� + �����Ϸ��� ���õǾ� ���� �߿��� �͵��̴�
�� �缱�� = ����� ���� ����

���� �缱���� �ʿ��Ѱ�?? ����Ѵٸ� �����ؼ� ����ϰ� ����� ������ �ʿ䰡 �ִ�!!

*/
#include <stdio.h>
//����!!
int g_nData; 
void Testfunc(int);
void Testfunc_New(int);

//����� ���� ����
typedef enum Color { RED , GREEN , BLUE } Color;

//�ܺ� ���� ����!!
extern int g_nData_Test; //"�̹�" �ܺ� ~~.c�� ���� �Ǿ� �ִ� ������ ���� ����!! 


int main(void) {
	Color RedNumber = RED;
	Color GreenNumber = GREEN;
	printf("Code split\n");
	//int g_nData; �������� ������ ������ ������ �߻� �Ѵ�
	printf("g_nData_Test : %d\n", g_nData_Test);
	printf("g_nData : %d\n", g_nData);
	Testfunc(100);
	Testfunc_New(10000);
	printf("g_nData_Test : %d (UpData g_nData Vaiable to Test.c)\n", g_nData_Test);
	printf("g_nData : %d (UpData g_nData Vaiable to Test.c)\n", g_nData);
	printf("Typedef Color RedNum :  %d , GreenNum : %d \n", RedNumber, GreenNumber);
	return 0;
}