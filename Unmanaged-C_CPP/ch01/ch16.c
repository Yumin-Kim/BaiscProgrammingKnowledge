/*
��ó����
�����Ϸ��� �ҽ��ڵ带 ������ �ϱ����� �̸� ����ó���ϴ°�
complie �� ó�� >> � ������ �ϴµ� ������ �� �� �������� �ǹ��� �־� �Ѵ�!!
�ֵ����� �ڵ��� ������ �Ѵ�!!(Ÿ�� , ������) 
cpu�� ������� �ƹ� ����� ����!! 
���� ������ Ÿ�ӿ��� �Ű澴��!!

#include <~~.h>	��𼱰� �˻��� �ؼ� ������ ���µ� �����Ϸ� ������ �ý��� directory(����)�ȿ� ���Ƽ� �ش�!!(�Ӽ��� ���Ե��丮���� ������ �´�!!)
#include ""		���� �������� �˻��Ŀ� ������ �´�!!

��� ���� ����� ������ #pragma once �ۼ��Ͽ� ��ó�����ѵ� �˷� ����Ѵ�!!
���� ������ �ѹ��� ~~.h�� �ص� ��� ����!!

���Ǻ� ��ġ���� #ifdef ,#else , #endif

��
������ n�� �����ϸ� ���Ǵ� 1ȸ�� ����!!
����鸸 ��Ƽ� ~~.h�� ������� include�ϰ� �Ǹ� ������ ���� �ۼ��ѰͰ� �Ȱ���!!
����� � ������ ���ԵǾ� �ִٰ� �����ϸ� �ȴ�!!

*/
#include <stdio.h>
//#include "TestPrintFunc.h"

//��ũ�� , __inline�� �ݽ��ÿ� ä������ �ʴ´�!! �����Ϸ��� �˾Ƽ� �õ��Ѵ�!!
//#define ADD(a,b)	(a+b)
#define _TEST_

void Testfunc(int);
void TestFunc_New(int nParam);
//__inline�� �Լ��� ����ȣ���ϴµ� ���� ������ ���⼺�� ���� ������ �����Ϸ��� ������ ���� �����ӿ� ä���� �ʰ� �����ϰ� ������ �ϱ� ���ؼ� �ÿ��Ѵ�
__inline int ADD(int a, int b) {
	return a + b;
}


int main(void) {
	Testfunc(100);
	//TestFunc_New(1000);
/*
#ifdef _TEST_
	Testfunc(100);
	TestFunc_New(1000);
	
#else
	TestPrintFunc(10);
#endif
	printf("��ũ�� �Լ� ��� %d", ADD(10, 20));
	return 0;
	*/
}