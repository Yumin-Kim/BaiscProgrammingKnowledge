#include <iostream>
/*
�Լ��� ���� �����̽�
�Լ� �������� �����Ѵ�!!
void TestFunc(int a);
void TestFunc(char * a);
�̷������� �Լ��� ������ �� �ִ�!!

Override ������
OVerloading ���� ����

C++���� ������ ���� ������ ������ ������ ���� ������ �Լ��� ������ ���� �������� �ʰ� ������ �ϰ� �Ǹ�
�Լ��� ������ ���̰� �ڿ��� �Լ��� ������ �� �� �ִ´� >> �̿� ���� ������ �Ǵ� ���� name mangling�̶�� �Ѵ�!!


�Լ� ���� ����
�Լ� �̸��� �ϳ� �ε� ���� �ǹ̸� ���ÿ� ���°��� ���Ѵ�!!

C++ ���ø��̶�� ������ �ְ� Class , Fucntion�� �ַ� ���ȴ� 
�� ���ø��� �ַ� ��� ���� ���ȴ�!!
Typescript , Java���׸� ���� ������ �ִ�

C++ namespace�� �ҼӰ� ���ٰ� �����ϸ� �ȴ�!!

*/


/*
void TestFunc(int a, int b = 100);
int Add(int a, int b);

double Add(double a, double b);
*/
//�Լ� ���ø����� �Ȱ��� ���� �� �� �ִ�!!
//T�� �ڷ����� caller�� ���� ��������!!
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
	//���� ������ ����ȴ�!!
	int g_nData = 100;
	int b = 100;
	/*
	ADD ��� �Լ��� �������� �����ϰ� namespace���� �����ϰ� �ȴٸ� ���� TestFunc���� ������ ADD�� namespace���� ADD�Լ��� ���� ������ namespace�� �Լ��� ����Ǵ¸���� �� �� �ִ�
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
//using�� namespace�� ��� �ϸ� namespace�� ���� �� �� �ִ�
//������ �ĺ��� �˻� �Ҷ� ������ �߻� �Ѵ�!!
 //���� (��������� ���Ҽ�)
 void PrintString(void) { cout << "::TestFunction()" << endl; }

 namespace Print {
	 //Print ���� �����̽� �Ҽ�
	 void PrintString(void) { cout << "Print::TestFunction()" << endl; }
 }
 //using�� ���ؼ� Print�� �����ϰ� PrintString�� �ϰ� �Ǹ� �����Ϸ��� ��ü������ ��ȣ���� �߰ߵǾ��ٰ� ������ �߻� �Ѵ�!!
 //using namespace Print;

int main(void) {
	//::���� ���� �����ڶ�� �Ѵ� Test(����,�Ҽ�)::a; 
	TestFunc();
	DEV::TestFunc();
	std::cout << "TEST  "<< Test::g_nData << "    " << Test::DEV::WIN::g_nData << std::endl;
	std::cout << Add(10, 20)<<'\t' <<Test::b << std::endl;
	std::cout << Add(10.55, 20.12) << std::endl;
	//c���� �ٸ��� �Լ� ����� �̸��� �������ִ� ���� �ƴ϶�  �Ҽӱ��� ���ִ°��� �´�!! 
	//���� , ���Ҽ� �϶� :: ������ִ� ���� �´�!!
	::PrintString();
	Print::PrintString();

}





 