#include <iostream>
using namespace std;
/*
복사 생성자와 임시 객체
생성자 함수

*/
class Test {
public:
	Test() { // Default
		cout << "Test()" << endl;
		n_nData = new int(0);
	}
	Test(int nParam) { // 반환 생성자
		cout << "Test(in nParma)" << endl;
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
	int GetData() {
		return *n_nData;
	}
	Test& operator = (const Test& rhs)
	{
		*n_nData = *rhs.n_nData;
		return *this;
	}
private://포인터 변수는 함부로 건드릴 수 없도록 private 접근 제어자를 사용한다
	int* n_nData = nullptr;
};

int main() {
	Test a; //Default
	Test b(a); // 복사 생성자 
	Test c(100); //반환 생성자 

	return 0;
}