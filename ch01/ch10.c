#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*
pointer 11�� 5,6 �ٽ� ����!!
���������Ϳ� �迭�� �迭
*/
int main() {
	char szSrcBuf[12] = { "Hello" };
	char szDstBuf[12] = { 0 };

	char* pszData = (char *)malloc(sizeof(char) * 12);

	//Deep copy (�ּ� ���� �ƴ� �ش��ϴ� �ּҿ� ��� ���� �����Ѵ�)
	memcpy(szDstBuf, szSrcBuf, sizeof(char) * 12);
	//shallow copy (���� ����� ���ڿ��� ��� �ּҰ��� ���� )
	pszData = szSrcBuf;

	printf("%s\n", pszData);
	//shallow copy�� ���ؼ� �����Ҵ� ���� ������ free�ҷ��ص� �Ҵ� ���� �ּҰ��� �𸣱� ������ ������ �߻� �Ѵ�
	//free(pszData);

	char szBuffer[12] = { "I am a boy." };
	char* pszFound = strstr(szBuffer, "am");
	int nIndex = pszFound - szBuffer;

	printf("%p\n", szBuffer);
	printf("%p\n", strstr(szBuffer, "am"));
	printf("%p\n", strstr(szBuffer, "boy"));
	printf("%d\n", nIndex);

	int alist[10] = { 0 };
	//�����Ϸ��� �ؼ��ϴ� ����
	//*plist�κ��� ���� Ȯ�� �Ͽ� 1. ������ �����̴ٸ� Ȯ���ϰ� �ڷ����� �������� Ȯ��!!

	//�������� �迭�� ���������� !!
	//���� ����!! �־��� stack������ �´ٸ� �̿� ���� �����Ѵ�!!
	*((int *)0x0019FE48) = 10;
	char* nTextObj[3] = { "Hello","World","Next" };
	//���� ���� �����ϸ� []���� �ؼ��ϰ� �״��� *�� �ؼ��� �ڷ������� �м��Ѵ�!!
	//static�� ����ϰ��Ǹ�  ���� ����ó�� ����� �� �ִ� >> ������ ���ü��� ������ �ֱ⶧���� ������� ����!!

}