#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	역호출의 중요성!!즉 CallBack구조!! 고성능 프로그램에서 주로 사용된다!!
	역호출은 내가 호출하는것이 아니고 자동으로 호출되는 것이다!!
	흐름이 중간에 안보이기 때문에 주의하는것이 좋다!!

	함수 포인터 + lookupTable을 같이 사용하게되면 switch ... case를 완벽하게 구현할 수 있다

	밑에서  qsort함수는 왜 callback구조로 만들어졌을까??
	다양한 자료형을 정렬하기 위해서 callback구조로 만들었다!!(비교 방법이 달라 질 수 있기 때문에)
	

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
	//함수 역호출의 예시!!
	//숫자배열
	int aList[5] = { 20,30,40,50,10 };
	qsort(aList, 5, sizeof(int), Swap_Dev);
	for (int i = 0; i < 5; i++)
		printf("%d\t", aList[i]);
	//이런식으로 매개 변수로 함수를 전달 할 수 있다 이 결과로 함수 이름 또한 메모리 주소을 가지고 있다는 점을 알 수 있다!!
	puts("");
	//문자배열
	char* pNameTable[5] = {
		"나라",
		"가지",
		"호두",
		"할아버지",
		"선생님"
	};
	qsort(pNameTable, 5, sizeof(int),Swap_Dev_char);
	for (int i = 0; i < 5; i++)
		printf("%s\t", pNameTable[i]);
	putchar('\n');


	//함수 포인터와 lookuptalbe
	//배열안에 함수를 담는다
	int userSelectNum = 0;
	void(*pszFuncList[3])(int)  = {
		TestFunc_1,
		TestFunc_2,
		TestFunc_3
	};
	printf("숫자를 입력하세요 : 0-3\n");
	scanf_s("%d", &userSelectNum);
	pszFuncList[userSelectNum](10);



	MyTest(TestFunc, 100);
}