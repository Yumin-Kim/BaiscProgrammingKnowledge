#include <iostream>
using namespace std;

class CTest {
public:
	CTest() {
		cout << "CTest()" << endl;
	}

	CTest(const CTest& ctest) {
		cout << "CTest(const CTest &ctest)" << endl;
		//복사 생성자를 사용했을때 밑에 있는 코드를 통해 멤버 변수를 똑같이 정의 할 수 있다!!( 멤버 값을 단순 대입으로 복사 )
		this->n_nData = ctest.n_nData;
	}

	~CTest() {
		cout << "~CTest()" << endl;
	}
	int n_nData = 0;
};


class CTest_Pointer {
public:
	CTest_Pointer() {
		cout << "CTest()" << endl;
		n_nData = new int(10);
	}
	//shallow copy할때 참조하는 과정을 알아 볼 수 있고 밑에 코드를 통해 Deep copy를 할 수 있다!!
	CTest_Pointer(const CTest_Pointer& ctest) {
		cout << "CTest_Pointer (const CTest_Pointer  &ctest)" << endl;
		//복사 생성자를 사용했을때 밑에 있는 코드를 통해 멤버 변수를 똑같이 정의 할 수 있다!!( 멤버 값을 단순 대입으로 복사 )
		this->n_nData = new int(*ctest.n_nData);
	}
	~CTest_Pointer() {
		cout << "~CTest_Pointer ()" << endl;
		delete n_nData;
	}

	void SetData(int nParam) {
		*n_nData = nParam;
	}
	int GetData() {
		return *n_nData;
	}

private://포인터 변수는 함부로 건드릴 수 없도록 private 접근 제어자를 사용한다
	int* n_nData = nullptr;
};

class Test {
public:
	Test() { // Default
		cout << "Test()" << endl;
		n_nData = new int(0);
	}
	Test(int nParam) {
		cout << "Test(in nParma)" << endl;

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
	int GetData() {
		return *n_nData;
	}

	Test &operator = (const Test &rhs)
	{
		*n_nData = *rhs.n_nData;
		return *this;
	}

private://포인터 변수는 함부로 건드릴 수 없도록 private 접근 제어자를 사용한다
	int* n_nData = nullptr;
};


int main() {
	int* p_A = new int(10);
	int* p_B = NULL;
	p_B = p_A;

	cout << *p_B << endl;
	cout << *p_A << endl;

	delete p_A;
	cout << *p_B << endl;
	cout << "Deep copy , Shallow copy _1" << endl;
	CTest a;
	a.n_nData = 100;
	//shallow copy여서 b의 n_nData가 0의 값이 된다
	CTest b(a); // 복사 생성자가 call된다!!

	cout << a.n_nData << endl;
	cout << b.n_nData << endl;

	CTest_Pointer test;
	test.SetData(100);
	CTest_Pointer copy(test);

	cout << test.GetData() << endl;
	cout << copy.GetData() << endl;
	//Deep copy , Shallow copy _2
	cout << "Deep copy , Shallow copy _2" << endl;
	Test test1;
	Test test2;

	test1.SetData(100);
	test2 = test1;

	cout << test1.GetData() << endl;
	cout << test2.GetData() << endl;

	cout << "main () return " << endl;
	return 0;
}