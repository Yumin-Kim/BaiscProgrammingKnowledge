#include <stdio.h>

/*
�迭
���ڿ��� �׻� �������� ���� �ΰ��� ����!!
���ڿ��� �����ºκп� NULL�� �ִ� ����?>
���ڿ��� ���� �ǹ��ϱ� ���ؼ�!!
*/

int main() {
	//�ִ밪 ���ϱ�!!
	int aList[5] = { 30,10,40,20,50 };
	int i = 0, nMax = aList[0];
	for (i = 1; i < 5; i++) {
		if (aList[i] > nMax) {
			nMax = aList[i];
		}
	}
	for (i = 0; i < 5; i++)
		printf("%d\t", aList[i]);

	putchar('\n');
	printf("Max : %d\n", nMax);

	printf("���ڿ� ��� ����!!\n");
	
	char szBuffer[6] = { 'H','e','l','l' ,'e' };
	char szData[8] = { "Hello" };

	puts(szBuffer);
	puts(szData);

	//������ �迭
	int multiMatrix[2][3] = { {1, 2, 3},{4, 5, 6} };
	//�޸� ������ 1��������(��������!!) �̷���� �־ �ؿ� �ִ� ���ó�� ������ �����ϴ�
	printf("%d\n", multiMatrix[0][3]);

	//������ �迭���� ��
	int multiMatixElements[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int totalNum = 0;
	int* pList = (int *)multiMatixElements;
	for (int i = 0; i < 12; i++)
	{
		//totalNum += pList[i];
		totalNum += ((int*)multiMatixElements)[i];
	}
	printf("%d\n", totalNum);

	//������ �迭 �����غ���!!


	//lookup Array
	//lookup Array�� ������� ���� �ʾҴٸ� ���ǹ��� ���� ���ǹ��� Ȱ�������ǵ� lookup Array�� ���� ���� ���ǹ��� ���ߴ�!!!
	//�����̶�� ������ �迭�� �������!!!(���ǹ��� �迭�� �쿴�ٰ� �����ϸ�ȴ�!!)
	double aRate[10] = {
		0.0 , 0.1,0.25,
		0.5 , 0.5,
		0.6,0.65,
		0.8,0.82,0.97,
	};

	int nAge = 0, nFee = 1000;
	printf("���ǥ\n");
	for (i = 1; i <= 10; i++)
		printf("%d����� : \t%d��\n", i, (int)(nFee * aRate[i - 1]));
	putchar('\n');

	printf("���̸� �Է��ϼ��� : ");
	scanf_s("%d", &nAge);
	if (nAge < 1) nAge = 1;
	else if (nAge > 10) nAge = 10;

	printf("���� ����� : %d\n", (int)(nFee * aRate[nAge - 1]));
	putchar('\n');
	return 0;
}