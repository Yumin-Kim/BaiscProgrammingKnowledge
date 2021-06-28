#include <iostream>
using namespace std;
/*
복사 생성자와 임시 객체
임시 객체를 존재하는 여부와 왜 존재하는지에 대해서 알고 있어야 한다
존재여부
int a = 0;
int b=0,c =0;
a = b +c ;

여기서 존재하는 int의 갯수는 총 4개 이다 개발자가 볼 수 있는 int형은 3개 + 임시 저장 Register에 저장되어 있는 int또한 있다는 것을 알 수 있다
만약 임시 저장 Register가 존재하지 않게 되면 우리가 원하는 연산이 진행되어도 그값이 a에 저장되지 않을 것이다
>> nResult = TestFunc() >>> 여기서도 볼 수 있듯이 과연 TestFunc()에서 Return된 값들은 어떻게 저장되어 오는지에 대한 의문에서 시작 될 수 있는데
그 의문은 Register에 임시 저장할 수 있는 기억 소자로 인해서 가능하다!!


생성자 함수

*/
class Test {
public:
	Test() { // Default
		cout << "Test()" << endl;
		n_nData = new int(0);
	}
	explicit Test(int nParam) { // 반환 생성자
		cout << "Test(int nParma)" << endl;
		n_nData = new int(nParam);
	}
	Test(const Test& test) { // Copy Constructor
		cout << "Test(const Test &test)" << endl;
		this->n_nData = new int(*test.n_nData);
	}
	~Test() { //소멸자
		cout << "~Test()" << endl;
		delete n_nData;
	}
	void SetData(int nParam) {
		*n_nData = nParam;
	}
	int GetData() const
	{
		return *n_nData;
	}
	Test& operator = (const Test& rhs)
	{
		*n_nData = *rhs.n_nData;
		return *this;
	}

	operator int(void)
	{
		return *n_nData;
	}

private://포인터 변수는 함부로 건드릴 수 없도록 private 접근 제어자를 사용한다
	int* n_nData = nullptr;
};
//참조자를 사용함으로서 생성자가 호출되지 않는다!
void TestFunc(const Test& test) {
	cout << "TestFunc() test.GetData()" << endl;
	cout << test.GetData() << endl;
}
//참조를 하지 않게 되어서 매개변수로 Test test(a) 이런식으로  선언한것과 같다!!
void TestFunc1(const Test test) {
	cout << "TestFunc_1() test.GetData()" << endl;
	cout << test.GetData() << endl;
}

Test* TestFunc2(void)
{
	Test* test = new Test(10);
	return test;
}

int PrintInt(void)
{
	return 10;
}

int main() {
	Test a(10); //Default
	Test b(20);
	int nResult = 0;
	nResult = a + 1000;
	//&&R-value의 값을 사용하기 위해서는 함수나 변수의 연산을 통해 반환 되어지는 값을 넣을 수 있다
	Test*&& operData = TestFunc2();
	int&& nData = PrintInt();
	cout << "nData &&" << nData << endl;


	/*
	Test b(a); // 복사 생성자
	Test c(100); //변환 생성자
	*/
	//이렇게 사용히게 되면 복사 생성자가 호출 된다!!
	//TestFunc(a);
	cout << "&nParam" << endl;
	TestFunc(a);
	cout << "nParam" << endl;
	TestFunc1(a);
	cout << "Test* TestFunc()" << endl;
	TestFunc2();

	return 0;
}