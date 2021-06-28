#include <iostream>
using namespace std;
/*
������ ���� ����



*/


class CMyData 
{
public:
	CMyData() 
	{
		cout << "CMyData()" << endl;
	}
	CMyData(const CMyData &rhs) 
	{
		cout << "CMyData(const CMyData &)" << endl;
	}
	CMyData(const CMyData&& rhs)
	{
		cout << "CMyData(const CMyData &&)" << endl;
	}
	CMyData( int nParam)
		:m_nData(nParam)
	{
		cout << "CMyData(int)" << endl;
	}
	~CMyData() 
	{
		cout << "~CMyData()" << endl;
	}

	int GetData() const
	{
		return m_nData;
	}

	void SetData(int nParam)
	{
		m_nData = nParam;
	}
	///////////////////////////////////////////////////////
	//������ �Լ�(���Ǵ� ��ȯ!!)
	/*
	operator int(void)
	{
		return m_nData;
	}
	*/
	CMyData& operator = (const CMyData &rhs)
	{
		SetData(rhs.GetData());
		return *this;
	}
	
	int operator = (int nParam)
	{
		//m_nData = nParam;  SetData�� ������ �ڵ�
		SetData(nParam);
		return m_nData;
	}
	// �ӽ� ��ü�� �����ǰ� ������� �ڵ带 �� �� �ִ�!
	CMyData operator+(const CMyData &rhs)
	{
		return CMyData(this->m_nData + rhs.m_nData);
	} 
	///////////////////////////////////////////////////////
private: // C++11���� ���� �ϴ�!!
	int m_nData = 0;
};

int main()
{
	CMyData a;
	CMyData b; // ���� ������ ȣ��!!
	CMyData c;

	c = a + b;

	// Ư���ϰ� ������� �Լ� �̴�!!
	//a = 10;
	//a = c = 100;
	//a.operator=(100);

//	c = 10;
	//operator int(void)�� ���� �ؿ� ������ �����ϰ� �ȴ�(�����Ϸ��� �˾Ƽ� ���ְ� �ȴ�!!)>> �����Ϸ��� ������ �κп����� ���� �� �˾Ƽ� ������ ���ذԵǴµ� �����Ұ�!!
	//a + b;
	//cout << a + c << endl;
	cout << "End of Main()" << endl;
	return 0;

}