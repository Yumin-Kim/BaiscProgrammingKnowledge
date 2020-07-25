#include <stdio.h>
#include <string.h>
/*
ch11에서 확인 할 수 있다!!
스택 프레임을 이해 하면 재귀호출등 함수 관련해서는 문제가 없다!!

재귀 함수 vs for + stack!! 비교하면 어느것이 성능적으로 좋은지??'
재귀 함수를 사용하기 위해서 call하게되는데 call함에 따라 overhead 발생 , stack 증가및 회복 , 매개변수 복사가 이루어져 많은 일을 통해 성능면에서는 좋지않다!!
call에 따른 overhead을 해결하기위해 매크로 함수와 인라인함수가 등장함에 편리해졌다

문자열에서 원하는 문자열을 할당하지 못할때는 상수화 되었다고한다!!

)사용자로 부터 문자열을 입력받는경우
가변길이(이름)을 고정 길이 메모리에 담는 경우에 Buffer overflow가 발생하는 문제를 배제 할 수 없다!! 
이런 경우가 발생하기전에 문자열을 검사를 통해 보안 결함을 막아야 한다

팁:
해킹은 결함을 통해 주기적으로 공격을 하여 하는것이다!!

*/
//호출 스택에 채워졌다가 빠져 나가는 모습 또한 볼 수 있다!!
void TestPrint(void) {
	int nData = 10;
	printf("TestPrint\n");
	return;
}

int* TestFunc(void) {
	int nData = 10;
	//Debug 모드 진행시 호출 스택에서 printf의 함수가 들어 가는 것을 볼 수 있다!!
	printf("%d\n", nData);
	TestPrint();
	return &nData;
}

int main() {
	//변수를 선언하고 그후 다른 변수를 선언할때마다 메모리의 주소값이 줄어들며 변수나 함수를 선언할때마다 스택에 쌓인다고 생각하면 될거 같다!!
	//스택의 가장 최 하단에 가까울수록 메모리의 주소값이 커짐!!
	
	int ntestMemory = 10;
	printf("%d\n", *TestFunc());
	//유니코드 선언하는 방식이며 2byte의 크기를 가지고 있다
	//윈도우는 유니코드를 많이 활용하고 리눅스 계열에서는 char를 사용한다!!
	//단어 끝나는 부분이 아니고 하나의 문자가 끝날때마다 null이 추가된다!!
	wchar_t wcsBuffer[12] = { L"Unicode" };
	puts(wcsBuffer);
	_putws(wcsBuffer);


	return 0;

}