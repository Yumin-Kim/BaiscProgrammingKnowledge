#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
int main() {
	int n;
	int arr[100];
	/*
	do {//do 사용시 한번 실행후 조건맞으면 계속 반복문 실행
		printf("숫자를 입력하세요\n");
		scanf_s("%d", &n);
		printf("%d", n);
	} while (n != 0);
	
	scanf_s("%d", &n);
	//for (int i = 1; ; i++) { //for 조건을 안적을시 무한 반복 실행
		//printf("%d", n);
	//}
	int arr[] = { 1,3,4,5,6,7 }; // int가 4byte이기 때문에 요소 갯수 곱하기 4바이트가된다
	printf("%d \n", sizeof(arr) / sizeof(int) -1);
	
	for (int i = 1, t = 1; i <= n; i++, t *= 2) {
		printf("2  ^ %d = %d\n", i, t);
	}
	
	printf("몇개의 숫자를 입력하실껀지?");
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
	//문자열은 마지막에 \0이 붙어서 이 문자열의 끝을 알려 준다
	char str1[] = "Hello";
	char str2[100];
	char str3[] = "HelLo";
	int len;
	len = strlen(str1);

	printf("%d\n", len);
	//strcmp 문자열을 복사 하는건데 첫번쨰 인자가 복사될것이고 두번째는 복사하려는 자료형이다
	strcpy(str2,str1);
	printf("%s\n", str2);
	//strcat 문자열을 덧붙여 주는 메서드
	strcat(str2, "world");
	printf("%s\n", str2);
	//strcmp 문자열 요소 비교 해주는데 첫번째 인자가 크면 1 작으면 -1 같으면 0
	n = strcmp(str1, str3);
	printf("%d\n", n);

	return 0;
}