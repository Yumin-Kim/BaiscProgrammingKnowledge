#include <stdio.h>
/*
�����Ϳ� �޸�
�ǽ��� �Ӽ� >> ��Ŀ >> ���� �����ּ� ���� Ǯ�� �ǽ��ϱ�!!

300�� 16�������� ǥ���ϰԵǸ�
0x00 00 01 2C
�޸𸮿� ǥ���Ǵ� �����
2C 01 00 00
�̿� ���� ����� Byte Order�̸� ���� ���� ���� �� ���� ���� ����� Littile Endian ����̴�!!
Little Endian ����� ü���� ���� intel!! 
�� cpu�� intel�� ������ �Ǿ Little Endian ������� �޸𸮿� ����!!

������ �޸𸮷� �����Ǿ���!!
��� �޸𸮴� �ּҸ� ������ &�����ڸ� Ȱ���Ͽ� �ּҸ� Ȯ�� �� �� �ִ�!!
&�� compile Time�� �������̴�!!
�ѹ� compile ���ķδ� �Ű澲�� �ʴ� �������̴�!!

���� ���� ������ ���� ���� (�޸𸮸� ���� ���� �ߴٴ� �ǹ��̴�)

���� ����!!
������ Ȱ��!!
�ؿ� ������ ������Ѱ����� ���ԵǸ� npnData�� �ּҰ��� nData�� �ٸ����� ������ �� �� �ְ�
npnData�� �޸��� ������ nData�� �ּҰ��� Little Endian ������� ���°��� �� �� �ִ�

�ѹ��� ����!!
�����͸� ����ϴ�����??
�Լ��� �迭�� �����ϴ� �κп��� �������� ����� �ش�ȭ �ȴ�!!
�Լ��� �������� �и��Ǿ ȿ���� �ش�ȭ�ȴ�!!

�츮�� ����ϴ� �޸𸮴� virtual Memorry�� ����ϰ� �ִ�!!

*/
int main() {

	int nData = 300;
	int* pnData = &nData;
	//�޸��� �ּҰ� ����!! int�� ũ�� ��ŭ ��������� nData�� �ּҰ����� 8byte���� �ڿ� �ִ� �޸��� �ּҰ����� �̵��ϰԵȴ�1!! 
	pnData += 2;
	//����� �޸� �ּҿ� 300�̶� ���ڰ� 16�������� ������ Little endian������� �߰��ȴ�!!
	*pnData = 300;

	//�����͸� Ȱ���� ���� �����ϴ� ���!!
	*((int*)0x0019FED8) = 100;

	int aList[4] = { 1,2,3,4 };
	int* paList = aList;
	/*
	paList[4] = 10;
	*(paList + 1) = 100; //paList[1]�� ���� �ǹ��̴�!!
	*/
	int bList[5] = { 40,20,50,30,10 };
	int nTotal = 0;

	for (int i = 0; i < 5; i++)
		nTotal += bList[i];
	printf("%d\n", nTotal);

	nTotal = 0;
	int* pnData_ = bList;
	while (pnData_ < bList + 5) {
		nTotal += *pnData_;
		pnData_++;
	}
	printf("%d",nTotal);
	return 0;
}