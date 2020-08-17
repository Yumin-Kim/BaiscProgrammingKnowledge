#include <iostream>
using namespace std;
/*
상속
1. 코드 재사용
2. 규모 확장
3. 관계의 한 유형에 포함!!

설계 << 객체구성 + 관계정의 하는것을 설계라고 한다!!

개발시 재건축하는 부분보다 리모데링 핤 수 있게 설계 해야한다!!
Class 간의 관계 파악 또한 중요하다!!
설계원칙 SOLID 원칙이 있다
과거의 개발된 것을 분석 할때는 관계 : 의존 관계(상속(존립) ,집합관계)
개발 순서 UI개발 >> DATA개발 >> S/W(process/Thread관리!!)

class Method는 
일반 >> 접근형식을 따른다!!
Virtual >> 실 형식을 따른다!!
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
	//생성자 상속!!
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
	자식 클레스를 선언하게 되면 각기 클래스의 생성자가 호출될것이다 
	디버그 모드로 보게되면 자식 클래스의 생성자가 호출되게 되지만 실행은 되지 않고 부모 생성자까지 제어가 올라가서 부모의 생성자가 호출됨과 동시에 실행된후에  자식 생성자가 실행되는 모습을 볼 수 있다
	즉 상속 받은 클래스간의 생성자 호출과 실행은 일치되지 않는면을 알 수 있다!!
	생성자에서는  객체에서는  객체 자신을 초기화 할 수 있는 코드만 넣어준다!!
	상속 할 시 파생 생성자(자식)에서는 절대로 부모 멤버 초기화를 하지 말것!!

	클래스간의 멤버 변수는 최대한 private 접근자를 사용한다!!(파생된 클래스의 접근을 막기 위해서! !)

	data.SetData(10);
	cout << data.GetData() << endl;
	dataEx.PrintData();
	*/
	//상속애서는 파생형식으로 되었어 기본 형식으로 Pointing이 된다!!(추상형식) 비유하면 사람(abastract) >> 학생(implment) Pointing 가능하다!!
	CMyDataEx a; // 실형식
	CMyData& b = a; //접근 형식
	b.PrintData();

	return 0;

}