#include <iostream>
using namespace std;
/*
연산자 다중 정의



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
	//연산자 함수(허용되는 변환!!)
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
		//m_nData = nParam;  SetData와 동일한 코드
		SetData(nParam);
		return m_nData;
	}
	// 임시 객체가 생성되고 사라지는 코드를 볼 수 있다!
	CMyData operator+(const CMyData &rhs)
	{
		return CMyData(this->m_nData + rhs.m_nData);
	} 
	///////////////////////////////////////////////////////
private: // C++11부터 가능 하다!!
	int m_nData = 0;
};

int main()
{
	CMyData a;
	CMyData b; // 복사 생성자 호출!!
	CMyData c;

	c = a + b;

	// 특수하게 만들어진 함수 이다!!
	//a = 10;
	//a = c = 100;
	//a.operator=(100);

//	c = 10;
	//operator int(void)를 통해 밑에 연산이 가능하게 된다(컴파일러가 알아서 해주게 된다!!)>> 컴파일러가 생성자 부분에서는 더욱 더 알아서 컴파일 해준게되는데 주의할것!!
	//a + b;
	//cout << a + c << endl;
	cout << "End of Main()" << endl;
	return 0;

}