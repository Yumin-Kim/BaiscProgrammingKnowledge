#include <stdio.h>
/*
���� �����
File�� ������忡�� Ŀ�θ��� ������ �� �ִ� �������̽� ������ �Ѵ�!!
���ϸ��� ������ I/O ���۰� �ִ�!!
�⺻������ ������ �������� >> streamimg�� �ȴ�!!
stream�̵Ǹ� buffer�� �������� �ϸ� Queue������ �̷�����ִ�!!
������ ����ϴ� ������ Disk(������� ��ġ)�� ����ϴ� ����̴�!!
ũ��� ��뷮������ �ӵ��� �����̴�!!
����� ������ �ִµ� �� �������� ����(����)�ϰԵǴµ� �� ���������� ũ��� 0�̴�!!
ũ�Ⱑ 0������ ������ Disk ��ü�� �ǹ��Ѵ� ������ write�� ������ ���� ��� �ʱ� ����� �������� ������ ũ�⸸ŭ
���� ������ ���� ������ ������ �ٽ� ����� �������� �����ϰԵȴ�!!
�̾ �߰����� write������ �������� ����� �������� ���Ͱ��� ������ �߰������� �����ϰԵȴ�!!
���� �޸𸮴� RAM�� ����ϴ� ����̸�
File�� Disk�� ����ϴ� ����̴�!!
�ؽ�Ʈ ���ϰ� ���̳ʸ� ������ ���� : "-1"�� EOF(End Of File)���ν� -1�� �ߴ������� ���ϸ� �ؽ�Ʈ ����
�׷��� �ʰ� �׳� �ؽ�Ʈ�� �ν��Ѵٸ� ���̳ʸ� ����!!

*/
int main(void)
{
	//w�� ������ ���� ������ ������ ����
	FILE* fp = NULL;
	fopen_s(&fp,"Text.txt", "wt");
	//���� ���� CON������ Console���� �츮�� �Է��� ���ڿ����� ���δ�!! 
	//fopen_s(&fp,"CON", "wt");
	fprintf(fp, "Hello FIle I/o\n");
	fclose(fp);
	system("Text.txt");
	printf("Hello");
	return 0;
}