#include <iostream>
using namespace std;
/*
���
1. �ڵ� ����
2. �Ը� Ȯ��
3. ������ �� ������ ����!!

���� << ��ü���� + �������� �ϴ°��� ������ �Ѵ�!!

���߽� ������ϴ� �κк��� ���𵥸� �A �� �ְ� ���� �ؾ��Ѵ�!!
Class ���� ���� �ľ� ���� �߿��ϴ�!!
�����Ģ SOLID ��Ģ�� �ִ�
������ ���ߵ� ���� �м� �Ҷ��� ���� : ���� ����(���(����) ,���հ���)
���� ���� UI���� >> DATA���� >> S/W(process/Thread����!!)

class Method�� 
�Ϲ� >> ���������� ������!!
Virtual >> �� ������ ������!!
static

*/

class CMyData
{
public:
	CMyData()
	{
		cout << "CMyData()" << endl;
	}
	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
	void PrintData() { cout << "CMyData :: PrintData()" << endl; }
private :
	int m_nData = 0;
};
class CMyDataEx : public CMyData
{
public:
	//������ ���!!
	using CMyData::CMyData;
	CMyDataEx()
	{
		cout << "CMyDataEX()" << endl;
	}
	void TestFunc() {
		PrintData();
		SetData(5);
		cout << GetData() << endl;
	}
	void PrintData() { cout << "CMyDataEx :: PrintData()" << endl; }
};

int main()
{
	/*
	
	CMyData data;
	CMyDataEx dataEx;
	�ڽ� Ŭ������ �����ϰ� �Ǹ� ���� Ŭ������ �����ڰ� ȣ��ɰ��̴� 
	����� ���� ���ԵǸ� �ڽ� Ŭ������ �����ڰ� ȣ��ǰ� ������ ������ ���� �ʰ� �θ� �����ڱ��� ��� �ö󰡼� �θ��� �����ڰ� ȣ��ʰ� ���ÿ� ������Ŀ�  �ڽ� �����ڰ� ����Ǵ� ����� �� �� �ִ�
	�� ��� ���� Ŭ�������� ������ ȣ��� ������ ��ġ���� �ʴ¸��� �� �� �ִ�!!
	�����ڿ�����  ��ü������  ��ü �ڽ��� �ʱ�ȭ �� �� �ִ� �ڵ常 �־��ش�!!
	��� �� �� �Ļ� ������(�ڽ�)������ ����� �θ� ��� �ʱ�ȭ�� ���� ����!!

	Ŭ�������� ��� ������ �ִ��� private �����ڸ� ����Ѵ�!!(�Ļ��� Ŭ������ ������ ���� ���ؼ�! !)

	data.SetData(10);
	cout << data.GetData() << endl;
	dataEx.PrintData();
	*/
	//��Ӿּ��� �Ļ��������� �Ǿ��� �⺻ �������� Pointing�� �ȴ�!!(�߻�����) �����ϸ� ���(abastract) >> �л�(implment) Pointing �����ϴ�!!
	CMyDataEx a; // ������
	CMyData& b = a; //���� ����
	b.PrintData();

	return 0;

}