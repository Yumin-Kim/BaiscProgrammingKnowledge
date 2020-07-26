#include <stdio.h>
/*
함수에 대한 고급 이론!~
함수이름 또한 주소 상수이다!!

함수형식이라는 자료형이 있다
함수형은 반환 형식 + 호출 규칙 + 이름(매개변수)가 있다!!
함수의 이름또한 주소를 담고 기계어로 번역 또한 되고 메모리 어디인가에 저장되고 Read만 되고 Write는 되지않고 실행된다!!
Write가 된게되면 연산에 오류가 생겨서 되지 않는다!!

성능향상을 위해 옛날에는 매크로를 많이 사용했지만 최근에는 __inline을 많이 사용한다!!
__inline은 Release 빌드시에 컴파일러가 최적화 하여 빌드하지 않고 넘어간다!!
매크로는 함수 인거 처럼 동작하지만 매개변수의 자료형 문제 지역변수 제어문 문제에 제약이 많기 때문에 __inline 함수가 필요하다!!

*/
// 함수 호출 규칙은 __cdecl로 되어 있다!!
/*
main 함수를 통해 GetMax()함수가 호출되게 되는데
호출로 인해 call스택에서 main >> GetMax 쌓이게 되고 GetMax(int a, int b , int c)의 매개 변수인 a, b ,c 가 스택에 쌓이게 되는데
c >> b >> a 순서로 쌓이게 된고 그다음 GetMax안에 있는 nMax인 지역변수가 쌓이게 된다!!

__cdecl은
함수가 끝나면 GetMax 호출전 스택을 스택의 top점을 자동으로 정리해주는데 이현상을 ESP(Export Stack Pointer) Register가 해준다!!
이런 점을 보아서 자동 변수라고 한다!!

__stdcall을 사용하게 되면 디스어셈블리 코드로 변형후에 호출하는 부분을 확인하게 되면
esp가 없어지게되고 callstack을 정리하지 않는 모습을 볼 수 있다!!
RAM >> RAM으로 카피 발생!!

__fastcall stdcall과 동일하게 동작!!
Register >> RAM으로 카피 발생

이모든것은 컴파일러가 알아서 결정한다!!
결론적으론 함수에서 callstack을 정리하는 모습을 볼 수 있다!!

*/
int __cdecl GetMax(int a , int b , int c ) {
	int nMax = a;
	if (b > nMax) nMax = b;
	if (c > nMax) nMax = c;
	return nMax;
}
//밑에서 강제 형 변환 한 모습과 비교하기!!
//int  (*이름)	(char*)
  int TestFunc(char * nParam) {
	return 100;
}

int main()
{
	int nResult = 10;
	GetMax(1,2,3);
	//main함수를 포인터에 저장하는 것으로 보아 함수 이름 또한 주소이며 포인터 변수에 담을 수 있다
	void* pnData = main;
	printf("%p\n",pnData);
	printf("%p\n",main);

	/*
	함수에서 ()또한 연산자이며 호출 연산자라고 한다!!
	함수형은 밑에 설명과 같다
	반환 자료형 ( 호출 규칙 * 변수이름 ) (매개변수)
	*/
	TestFunc("");
	//밑에 코드는 자료형이 맞지 않다고 경고가 뜬다!!
	//int nData = TestFunc;
	 
	int nData = (int)TestFunc;

	//nData를 강제로 형 변환 해서 호출하는 방법이며 int형에 포인터를 반환하고 매개변수는 char 포인터라고 형변환한후에 호출 연산자를 사용하면 된다!!
	printf("%d\n", ( (int(*)(char*) ) nData)(""));

	//일반 변수에 담아서 호출 하는 방법 또한 있다 
	int (__cdecl * pszFuncVariable)(int , int , int ) = GetMax;
	printf("pszFuncVariable : %d \n", pszFuncVariable(1, 2, 3));

	printf("Hello");
	return 0;
}