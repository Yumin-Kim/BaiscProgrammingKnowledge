#include <iostream>
using namespace std;
/*
���� �����ڿ� �ӽ� ��ü
������ �Լ�

*/
class Test {
public:
	Test() { // Default
		cout << "Test()" << endl;
		n_nData = new int(0);
	}
	Test(int nParam) { // ��ȯ ������
		cout << "Test(in nParma)" << endl;
		n_nData = new int(nParam);
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
	Test& operator = (const Test& rhs)
	{
		*n_nData = *rhs.n_nData;
		return *this;
	}
private://������ ������ �Ժη� �ǵ帱 �� ������ private ���� �����ڸ� ����Ѵ�
	int* n_nData = nullptr;
};

int main() {
	Test a; //Default
	Test b(a); // ���� ������ 
	Test c(100); //��ȯ ������ 

	return 0;
}