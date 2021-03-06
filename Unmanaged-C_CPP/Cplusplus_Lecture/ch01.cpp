#include <iostream>
/*
함수와 네임 스페이스
함수 다형성을 제공한다!!
void TestFunc(int a);
void TestFunc(char * a);
이런식으로 함수를 선언할 수 있다!!

Override 재정의
OVerloading 다중 정의

C++에서 재정의 다중 정의이 가능한 이유는 다중 정의할 함수를 원형만 쓰고 정의하지 않고 컴파일 하게 되면
함수의 원형이 보이고 뒤에는 함수의 본명을 볼 수 있는다 >> 이와 같이 컴파일 되는 것을 name mangling이라고 한다!!


함수 다중 정의
함수 이름은 하나 인데 여러 의미를 동시에 갖는것을 말한다!!

C++ 템플릿이라는 개념이 있고 Class , Fucntion에 주로 사용된다 
이 텟플릿은 주로 찍어 낼때 사용된다!!
Typescript , Java제네릭 같은 느낌이 있다

C++ namespace는 소속과 같다고 생각하면 된다!!

*/


/*
void TestFunc(int a, int b = 100);
int Add(int a, int b);

double Add(double a, double b);
*/
//함수 템플릿으로 똑같이 구현 할 수 있다!!
//T의 자료형은 caller에 따라 정해진다!!
template <typename T>
T Add(T a, T b)
{
	return a + b;
}
int ADD(int a, int b) {
	printf("global Function\n");
	return a + b;
}
 namespace Test {
	//전역 변수로 선언된다!!
	int g_nData = 100;
	int b = 100;
	/*
	ADD 라는 함수를 전역에도 선언하고 namespace에도 선언하게 된다면 현재 TestFunc에서 선언한 ADD는 namespace부터 ADD함수를 칮기 때문에 namespace의 함수가 실행되는모습을 볼 수 있다
	*/
	int ADD(int a, int b) {
		printf("Test Namesace ADD function\n");
		return a + b;
	}
	
	void TestFunc() {
		std::cout << "Test NameSpace TestFunction" << std::endl;
		ADD(10, 20);
	}
	namespace DEV {
		void TestFunc() {
			std::cout << "Dev NameSpace TestFunction" << g_nData << std::endl;
		}	
		namespace WIN {
			int g_nData = 300;
		}
	}

}
 using namespace Test;
 using namespace std;
//using을 namespace에 사용 하면 namespace를 생략 할 수 있다
//하지만 식별자 검색 할때 문제가 발생 한다!!
 //전역 (개념상으론 무소속)
 void PrintString(void) { cout << "::TestFunction()" << endl; }

 namespace Print {
	 //Print 네임 스페이스 소속
	 void PrintString(void) { cout << "Print::TestFunction()" << endl; }
 }
 //using을 통해서 Print를 생략하고 PrintString을 하게 되면 컴파일러가 자체적으로 모호성이 발견되었다고 오류가 발생 한다!!
 //using namespace Print;

int main(void) {
	//::범위 지정 연산자라고 한다 Test(범위,소속)::a; 
	TestFunc();
	DEV::TestFunc();
	std::cout << "TEST  "<< Test::g_nData << "    " << Test::DEV::WIN::g_nData << std::endl;
	std::cout << Add(10, 20)<<'\t' <<Test::b << std::endl;
	std::cout << Add(10.55, 20.12) << std::endl;
	//c언어와 다르게 함수 선언시 이름만 선언해주는 것이 아니라  소속까지 써주는것이 맞다!! 
	//전역 , 무소속 일때 :: 사용해주는 것이 맞다!!
	::PrintString();
	Print::PrintString();

}





 