/*
객체 , 인스턴스의 의미 
인스턴스는 객체를 실제로 구성한 것 즉 어떤 메모리 공간에 구현된 실체를 말한다
객체는 클래스의 타입으로 선언되었을때 의미
TEST test; 객체 생성
여기서 이 객체ㄹ가 메모리에 할당 되어 실제 사용될 때를 인스턴스라고 하는것이다
인스턴스느 추상화 개념 또는 클래스 객체 컴퓨터 프로세스등과 같은 템플릿이 실제로 구현되는것이다
인스턴스화는 클래스 내의 객체에 대해 특정한 변형을 정의 한다
이름을 붙인 다음 그서을 물리적인 어떤 장소에 위치 시키는 작업을 통해 인스턴스를 만든다
변수도 하나의 인스턴스라고 말하는 이유는 실체는 메모리 값에 할당되기 때문에


*/

#include <iostream>
using namespace std;


class Test {
	static int i;
public:
	Test() {
		cout << "Test()" << endl;
		cout << i << endl;
	}
	void PrintTest();
};

void Test::PrintTest() {
	printf("::범위 지정자로 사용됩니다\n");
}

int Test::i = 100;

int main() {
	Test test;
	// new는 동적 메모리 할당을 하기 위해 사용하는 연산자로서 메모리 할당을 받기 위해서 pointer 연산자를 사용하는것이다
	Test* Newtest = new Test();
	test.PrintTest();
	delete Newtest;
	return 0;
}