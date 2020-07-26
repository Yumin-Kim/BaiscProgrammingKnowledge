#include <stdio.h>
#include "..\LibTest\LibTest.h"
/*
	정적 library구현!!
	라이브러리란 함수를 모아놓은 파일을 말하며 정적이라는것은 라이브러리를
	.c에서 complie를 거쳐 .obj로 만들어서 사용하는데 call을 자주하는 함수 이거나 다른 프로젝트에서도 사용되는 함수일때 똑같은 작업(컴파일,Link)를 반복적으로 하게되는데 이 작업을 
	안하기 위해서 lib(정적인 파일을 만들어) obj로 만들지 않고 다른 프로젝트에서도 사용할 수 있게 할 수 있다

	visual studio 안에 정적인 라이브러리 생성 킷을 사용하여 만들고 속성에 미리 컴파일된 해더를 제외 시켜준다!!

	하나의 솔루션에서 Lib을 위한 프로젝트 하나와 Main함수가 있는 프로젝트 하나를 사용하였고
	하나의 솔루션으로 구성되어 있어 모든 파일이 종속되어 있는모습을 볼수 있다(Lib폴더를 빌드하고 바로 실행 시켜도 변경 사항이 바로 반영 된다!!)
	정적 프로젝트를 빌드 하게 되면 전체 솔루션 폴더에서 Debug안에 프로젝트명.lib가 생성된는것을 볼 수 있다.

	.SDK파일이 있는데 이 파일은 .lib 파일의 집합체이고 개발자는 이 파일을 끌어다 쓰면 끝이다!!
	DLL파일은 Runtime에 사용되는데 Win프로그램할때 사용된다!!

	여러 lib 파일 끌어다 쓰게 되면 충돌이 나는데 이 문제를 해경하기 위해서 함수명을 변경하는수 밖에 없다!!

*/
//#pragma comment(lib,"..\\Debug\\LibTest.lib")

//void PrintValue(int);//complie오류는 피하지만 링커 오류 발생

int main(void) {
	PrintValue(10);
	PrintString("Static Libraty");
	return 0;
}