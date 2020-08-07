#include <iostream>
using namespace std;

class CTest {
public:
	CTest() {
		cout << "CTest()" << endl;
	}

	CTest(const CTest& ctest) {
		cout << "CTest(const CTest &ctest)" << endl;
		//���� �����ڸ� ��������� �ؿ� �ִ� �ڵ带 ���� ��� ������ �Ȱ��� ���� �� �� �ִ�!!( ��� ���� �ܼ� �������� ���� )
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
	//shallow copy�Ҷ� �����ϴ� ������ �˾� �� �� �ְ� �ؿ� �ڵ带 ���� Deep copy�� �� �� �ִ�!!
	CTest_Pointer(const CTest_Pointer& ctest) {
		cout << "CTest_Pointer (const CTest_Pointer  &ctest)" << endl;
		//���� �����ڸ� ��������� �ؿ� �ִ� �ڵ带 ���� ��� ������ �Ȱ��� ���� �� �� �ִ�!!( ��� ���� �ܼ� �������� ���� )
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

private://������ ������ �Ժη� �ǵ帱 �� ������ private ���� �����ڸ� ����Ѵ�
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
	~Test() { //�Ҹ���
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

private://������ ������ �Ժη� �ǵ帱 �� ������ private ���� �����ڸ� ����Ѵ�
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
	//shallow copy���� b�� n_nData�� 0�� ���� �ȴ�
	CTest b(a); // ���� �����ڰ� call�ȴ�!!

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