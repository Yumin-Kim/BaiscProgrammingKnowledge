#include <stdio.h>
//callback , ����� �ڵ� �м�!!
//���� ��������!!
//���ɿ� ���� ���ݺ�
//���ݺ񱳸� �ϰ� ���� �ٸ� ������ �Ѵٰ� ������ �Լ� �����Ϳ� lookupTable�� ������ �´�!!

//�������� >>  calling convention , �� ������� >> callback

int CheckPrice(double *Table ) {
	return 0;
}
void PrintService_1(int nServiceNum) {
	printf("1 �� ���� �Դϴ� :\n");
}

void PrintService_2(int nServiceNum) {
	printf("2 �� ���� �Դϴ� :\n");
}

void PrintService_3(int nServiceNum) {
	printf("3 �� ���� �Դϴ� :\n");
}

void PriceOfAgeCompareFunc_Age0(int nAge,double * Table)
{
	int ncustomer = 0;
	void(* pszServiceFunc[3])(int) = {
		PrintService_1,PrintService_2,PrintService_3
	};
	printf("���̴� %d , ���ݰ��� : %d\n",nAge , (int)(Table[nAge] * 1000));
	printf("ȸ���̸� 1,�ƴϸ� 0 : ");
	scanf_s("%d", &ncustomer);
	if (ncustomer == 1) {
		int nServiceNumber = 0;
		printf("�̿��� �� �ִ� ���񽺰� 1���� 3������ �ֽ��ϴ�\nȮ���Ͻ÷��� ��ȣ�� , ������ ������ -1 : ");
		scanf_s("%d", &nServiceNumber);
		printf("%d", nServiceNumber);
		nServiceNumber < -1 || nServiceNumber > 3 ? printf("���񼭺񽺴� 1���� 3�������ۿ� ���� ���� �ʽ��ϴ�\n") : pszServiceFunc[nServiceNumber](10) ;
	}
	printf("�����մϴ�!!\n");
}
#define ADD(a,b)	(a+b)

int __inline Add(int a , int b) {
	return a + b;
}

int multiply(int a , int b) {
	return a * b;
}

int main(void) 
{
	//1������
	double nPriceTable[10] = {
		0.2,0.25,0.27,
		0.3,0.35,0.37,
		0.6,0.77,0.8,
		0.94
	};
	int nInput = 0;
	printf("ADD macro : %d \n", ADD(10, 20));
	printf("add __inline : %d \n", Add(10, 20));
	printf("multiply __inline : %d \n", multiply (10, 20));
	/*
	while (1) {
		printf("������ ������ �Է��ϼ���->>�̸����� �Է����ּ���(1���̸� 0��!!)(���� -1) : ");
		scanf_s("%d", &nInput);
		//Looktable��������� 1����
		if(nInput < 0) 
		{
			printf("0���� �����Դϴ�!!\n");
			break;
		}
		else
		{
			printf("�Է��Ͻ� ���̴� :%d\n", nInput);
			PriceOfAgeCompareFunc_Age0(nInput, nPriceTable);
		}
	}
	*/
	return 0;
}