#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
int main() {
	int n;
	int arr[100];
	/*
	do {//do ���� �ѹ� ������ ���Ǹ����� ��� �ݺ��� ����
		printf("���ڸ� �Է��ϼ���\n");
		scanf_s("%d", &n);
		printf("%d", n);
	} while (n != 0);
	
	scanf_s("%d", &n);
	//for (int i = 1; ; i++) { //for ������ �������� ���� �ݺ� ����
		//printf("%d", n);
	//}
	int arr[] = { 1,3,4,5,6,7 }; // int�� 4byte�̱� ������ ��� ���� ���ϱ� 4����Ʈ���ȴ�
	printf("%d \n", sizeof(arr) / sizeof(int) -1);
	
	for (int i = 1, t = 1; i <= n; i++, t *= 2) {
		printf("2  ^ %d = %d\n", i, t);
	}
	
	printf("��� ���ڸ� �Է��Ͻǲ���?");
	scanf_s(" %d ", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	printf("%d \n", max);
	*/
	//���ڿ��� �������� \0�� �پ �� ���ڿ��� ���� �˷� �ش�
	char str1[] = "Hello";
	char str2[100];
	char str3[] = "HelLo";
	int len;
	len = strlen(str1);

	printf("%d\n", len);
	//strcmp ���ڿ��� ���� �ϴ°ǵ� ù���� ���ڰ� ����ɰ��̰� �ι�°�� �����Ϸ��� �ڷ����̴�
	strcpy(str2,str1);
	printf("%s\n", str2);
	//strcat ���ڿ��� ���ٿ� �ִ� �޼���
	strcat(str2, "world");
	printf("%s\n", str2);
	//strcmp ���ڿ� ��� �� ���ִµ� ù��° ���ڰ� ũ�� 1 ������ -1 ������ 0
	n = strcmp(str1, str3);
	printf("%d\n", n);

	return 0;
}