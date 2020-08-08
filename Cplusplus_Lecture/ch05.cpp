#include <iostream>
using namespace std;
/*
���� �����ڿ� �ӽ� ��ü
�ӽ� ��ü�� �����ϴ� ���ο� �� �����ϴ����� ���ؼ� �˰� �־�� �Ѵ�
���翩��
int a = 0;
int b=0,c =0;
a = b +c ;

���⼭ �����ϴ� int�� ������ �� 4�� �̴� �����ڰ� �� �� �ִ� int���� 3�� + �ӽ� ���� Register�� ����Ǿ� �ִ� int���� �ִٴ� ���� �� �� �ִ�
���� �ӽ� ���� Register�� �������� �ʰ� �Ǹ� �츮�� ���ϴ� ������ ����Ǿ �װ��� a�� ������� ���� ���̴�
>> nResult = TestFunc() >>> ���⼭�� �� �� �ֵ��� ���� TestFunc()���� Return�� ������ ��� ����Ǿ� �������� ���� �ǹ����� ���� �� �� �ִµ�
�� �ǹ��� Register�� �ӽ� ������ �� �ִ� ��� ���ڷ� ���ؼ� �����ϴ�!!


������ �Լ�

*/
class Test {
public:
	Test() { // Default
		cout << "Test()" << endl;
		n_nData = new int(0);
	}
	explicit Test(int nParam) { // ��ȯ ������
		cout << "Test(int nParma)" << endl;
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

private://������ ������ �Ժη� �ǵ帱 �� ������ private ���� �����ڸ� ����Ѵ�
	int* n_nData = nullptr;
};
//�����ڸ� ��������μ� �����ڰ� ȣ����� �ʴ´�!
void TestFunc(const Test& test) {
	cout << "TestFunc() test.GetData()" << endl;
	cout << test.GetData() << endl;
}
//������ ���� �ʰ� �Ǿ �Ű������� Test test(a) �̷�������  �����ѰͰ� ����!!
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
	//&&R-value�� ���� ����ϱ� ���ؼ��� �Լ��� ������ ������ ���� ��ȯ �Ǿ����� ���� ���� �� �ִ�
	Test*&& operData = TestFunc2();
	int&& nData = PrintInt();
	cout << "nData &&" << nData << endl;


	/*
	Test b(a); // ���� ������
	Test c(100); //��ȯ ������
	*/
	//�̷��� ������� �Ǹ� ���� �����ڰ� ȣ�� �ȴ�!!
	//TestFunc(a);
	cout << "&nParam" << endl;
	TestFunc(a);
	cout << "nParam" << endl;
	TestFunc1(a);
	cout << "Test* TestFunc()" << endl;
	TestFunc2();

	return 0;
}