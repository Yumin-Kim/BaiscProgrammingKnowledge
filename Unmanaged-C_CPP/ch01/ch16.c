/*
전처리기
컴파일러가 소스코드를 컴파일 하기전에 미리 선행처리하는것
complie 전 처리 >> 어떤 동작을 하는데 무엇을 할 수 있을까의 의문을 둬야 한다!!
주동작은 코드의 변형을 한다!!(타자 , 편집기) 
cpu의 연산과는 아무 상관이 없다!! 
오직 컴파일 타임에만 신경쓴다!!

#include <~~.h>	어디선가 검색을 해서 가지고 오는데 컴파일러 설정안 시스템 directory(폴더)안에 칮아서 준다!!(속성에 포함디렉토리에서 가지고 온다!!)
#include ""		현재 폴더에서 검색후에 가지고 온다!!

헤더 파일 선언시 무조건 #pragma once 작성하여 전처리기한데 알려 줘야한다!!
원형 선언을 한번에 ~~.h에 해도 상관 없다!!

조건부 전치리기 #ifdef ,#else , #endif

팁
선언은 n번 가능하며 정의는 1회만 가능!!
선언들만 모아서 ~~.h로 만드느데 include하게 되면 손으로 직접 작성한것과 똑같다!!
헤더는 어떤 선언이 포함되어 있다고 생각하면 된다!!

*/
#include <stdio.h>
//#include "TestPrintFunc.h"

//매크로 , __inline은 콜스택에 채워지지 않는다!! 컴파일러가 알아서 시도한다!!
//#define ADD(a,b)	(a+b)
#define _TEST_

void Testfunc(int);
void TestFunc_New(int nParam);
//__inline은 함수가 자주호출하는데 내부 로직은 복잡성이 높지 않을때 컴파일러가 스스로 스택 프레임에 채우지 않고 수월하게 동작을 하기 위해서 시용한다
__inline int ADD(int a, int b) {
	return a + b;
}


int main(void) {
	Testfunc(100);
	//TestFunc_New(1000);
/*
#ifdef _TEST_
	Testfunc(100);
	TestFunc_New(1000);
	
#else
	TestPrintFunc(10);
#endif
	printf("매크로 함수 사용 %d", ADD(10, 20));
	return 0;
	*/
}