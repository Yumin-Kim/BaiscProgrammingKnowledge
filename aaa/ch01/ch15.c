/*
선언과 정의 의 차이
선언이 있으면 정의또한 있어야 한다
선언은 개념 , 공약과 같다(문법때문에 하며 컴파일 타임에서 중요하다)
정의은 구현 , 이행과 같다(링크 타임에서 중요하면 잘못 구현시 링크 타임에 오류가 난다)

정의는 했지만 선언부분이 없으면 컴파일 오류가 발생 (extern에러)
선언은 했는데 정의 하지 않으면 Link오류가 발생하게 된다!!

.c의 용도는 정의의 용도!! >> 컴파일 후에는 .obj만들어 지고 여러 코드 분할 한후에 exe로 만드는 과정을 Link한다라고 한다!!
.h의 용도는 선언의 용도!!

현재 파일을 분할하여 프로그램을 작성했다
TestFunc()라는 함수를 정의한 파일인 Test.c
TestFunc()라는 함수를 선언한 파일인 ch15.c

이 두파일이 어떻게 합쳐 지는 것일까??
ch15.c,Test.c 컴파일 되면 .obj의 확정자를 가지고 컴파일이 이루어진다 
그후 각각 컴파일된 파일의  .obj을 보면 처음 부분에 Export table이 있다
Test.obj 파일의 table(Symbol table)안에  TestFunc()가 정의 되어 있다는 정보가 담겨 있다
link작업을 통해 .exe 파일을 생성하는데 생성하기 위해서는 obj 파일을 합치게된다!!
합치는 과정에서 TestFunc라는 부분이 선언되어 있고 call하는 부분(함수 호출)에서 Test.obj의 테이블을 뒤져서 정의 부분을 찾아서 임무를 수행하게 된다!!
정리하면 linktime(obj 파일을 합치는 과정)할때 main함수의 로직들이 실행되게 되는데 TestFunc call(TestFunc호출)을 만나게 되면 Test파일로 넘어가 TestFunc를 실행하게되고 실행이 끝나면 다시 main 함수로 돌아가 프로그램의 종료되게 된다!!
Linktime에서 중요한 점은 실제로 정의가 어디에 있는지를 찾는 역할을 한다!!

만약 Testfunc라는 함수를 재정의 하게 되면 컴파일 타임에서 오류가 나지않고 Link타입에서 에러가 나는 모습을 볼수 있다(에러 파일이 .obj에서 발생!!)
비유 하면 컴파일은 설계도를 통해 부품을 제작하는 과정이고 Link는 조립하는 과정이며 
Test.c , ch15.c , TestPrint.c 를 부품화하는데는 문제가 없지만 Link즉 조립하는 과정에서 부품이 두개여서 Link오류가 발생하게 된다!!

/////////////////////
선언은 문법 + 컴파일러에 관련되어 가장 중요한 것들이다
형 재선언 = 사용자 정의 형식

형식 재선언이 필요한가?? 사용한다면 주의해서 사용하고 사용을 자제할 필요가 있다!!

*/
#include <stdio.h>
//선언!!
int g_nData; 
void Testfunc(int);
void Testfunc_New(int);

//사용자 정의 선언
typedef enum Color { RED , GREEN , BLUE } Color;

//외부 변수 선언!!
extern int g_nData_Test; //"이미" 외부 ~~.c에 정의 되어 있는 변수에 대한 선언만!! 


int main(void) {
	Color RedNumber = RED;
	Color GreenNumber = GREEN;
	printf("Code split\n");
	//int g_nData; 선언하지 않으면 컴파일 오류가 발생 한다
	printf("g_nData_Test : %d\n", g_nData_Test);
	printf("g_nData : %d\n", g_nData);
	Testfunc(100);
	Testfunc_New(10000);
	printf("g_nData_Test : %d (UpData g_nData Vaiable to Test.c)\n", g_nData_Test);
	printf("g_nData : %d (UpData g_nData Vaiable to Test.c)\n", g_nData);
	printf("Typedef Color RedNum :  %d , GreenNum : %d \n", RedNumber, GreenNumber);
	return 0;
}