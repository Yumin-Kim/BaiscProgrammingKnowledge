#include <stdio.h>

/*
배열
문자열은 항상 가변적인 길이 인것을 인지!!
문자열이 끝나는부분에 NULL이 있는 이유?>
문자열의 끝을 의미하기 위해서!!
*/

int main() {
	//최대값 구하기!!
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

	printf("문자열 출력 연습!!\n");
	
	char szBuffer[6] = { 'H','e','l','l' ,'e' };
	char szData[8] = { "Hello" };

	puts(szBuffer);
	puts(szData);

	//다차원 배열
	int multiMatrix[2][3] = { {1, 2, 3},{4, 5, 6} };
	//메모리 구조가 1차원으로(선형구조!!) 이루어져 있어서 밑에 있는 방식처럼 접근이 가능하다
	printf("%d\n", multiMatrix[0][3]);

	//다차원 배열간의 합
	int multiMatixElements[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int totalNum = 0;
	int* pList = (int *)multiMatixElements;
	for (int i = 0; i < 12; i++)
	{
		//totalNum += pList[i];
		totalNum += ((int*)multiMatixElements)[i];
	}
	printf("%d\n", totalNum);

	//달팽이 배열 구현해보기!!


	//lookup Array
	//lookup Array를 사용하지 하지 않았다면 조건문을 다중 조건문을 활용했을건데 lookup Array를 통해 다중 조건문을 피했다!!!
	//선택이라는 개념을 배열로 만들었다!!!(조건문을 배열로 녹였다고 생각하면된다!!)
	double aRate[10] = {
		0.0 , 0.1,0.25,
		0.5 , 0.5,
		0.6,0.65,
		0.8,0.82,0.97,
	};

	int nAge = 0, nFee = 1000;
	printf("요금표\n");
	for (i = 1; i <= 10; i++)
		printf("%d세요금 : \t%d원\n", i, (int)(nFee * aRate[i - 1]));
	putchar('\n');

	printf("나이를 입력하세요 : ");
	scanf_s("%d", &nAge);
	if (nAge < 1) nAge = 1;
	else if (nAge > 10) nAge = 10;

	printf("최종 요금은 : %d\n", (int)(nFee * aRate[nAge - 1]));
	putchar('\n');
	return 0;
}