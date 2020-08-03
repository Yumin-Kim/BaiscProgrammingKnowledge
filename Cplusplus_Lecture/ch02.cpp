#include <iostream>
/*

객체란 변수들과 그와 관련된 메소드들이 모여서 이룬 하나의 꾸러미다
클래스란 C와 구조체에서 확장된 변수 객체 함수를 포함한 하나의 틀이다

사고의 전환이 필요하다
반드시 다수의 (여러분의 클래스를 가져다 사용하는 ) 사용자를 배려해야한다

왜 피곤하게 복잡한 코드를 만들지? 이런 생각을 할 수 있지만 무조건 코드를 작성할때는 다수의 사용자를 염두에 두고 작업해야한다!!

전환 후에는 사용자의 편의성을 극대화해야 하며 사용자의 실수 가능성을 재작자가 차단해야한다.
C++		C
Class = 구조체 + 함수 + 접근 제어자 + 상속

멤버는 Data , Function(Method)이 포함 되어 있다
외부(사용자사용)에서 내부(Class) 사용할때 접근 제어자가 필요하게 된다!!

휴대폰의 인터페이스(버튼 , 터치)등으로 사용자의 접근을 제어 하는 부분을 비유 할 수 있다	

C언어에서는 Struct는 접근 제어자가 없어서 하나의 자료구조가 된다
이런면을 통해 자유도가 높아 지는 모습을 보고 
C++에서는 이런 자유도를 억제 하기 위해 Class에서는 접근 제어자가 존재 한다

C : main()함수가 시작점!!
C++ : main()함수가 먼저 시작되지만 만약 전역 변수로 Class가 선언되었다면 생성자 함수가 먼저 실행된다

*/

using namespace std;
//Class가 생성되기 이전 stuct를 선언하고 안에 함수 포인터를 활용하여 객체 안에의 메소드(멤버변수)처럼 사용하였다!!
typedef struct USERDATA {
	int nAge;
	char szName[32];
	int(*AddToAge)(struct USERDATA * a,int b);
	void(*PrintValue)(struct USERDATA* a);
}USERDATA;

//struct  >> Class
class UserClass {
public:
	int nAge;
	char nName[100];
	~UserClass() {
		cout << "=============================================" << endl;
		cout << "Destory UserClass constructor Function (First declared Class)" << endl;
	}
	void Print(UserClass * userStruct) {
		int nData = 5;
		cout << "User Name" << userStruct->nName<< "User Age" << userStruct->nAge << endl;
	}
	//겉으로 보기에는 Class의 주소가 안넘어가는것 같지만 지역 변수를 선언하게 되면 지역 변수의 메모리 밑에 Class주소값이 들어 가는 모습을 볼 수 있다
	//hiden Paramter라고 하며 함수 내부적으로 사용할 수 있는 this 포인터를 사용하면 더 확실히 알 수 있다
	void Print2() {
		int nData = 5;
		cout << "User Name" << nName << "User Age" << nAge << endl;
		cout << "User Name(this Pointer)" << this->nName << "User Age(this Pointer)" << this->nAge << endl;
	}

};

class Test {
public :
	Test(int nParam) {
		nData = nParam;
		cout << "Test Class Constructor function" << endl;
	}
	/*
	소멸자 함수!! 선언 할시 ~를 사용한다!! main()함수 마지막 부에 실행된다(즉 지역 변수로 선언되었던 class들은!!)!!
	소멸자 함수가 호출된는것으로 보아 스택의 구조로 빠져 나오는 것을 볼 수 있다 
	(Main함수안이나 전역 변수 동일 마지막에 선언,정의한 Class의 소멸자 함수가 실행되고 그다음 마지막순서로 선언,정의된 Class 소멸자가 호출되는 모습을 볼 수 있다)
	위에서 설명한것과 같이 프로그램이 시작되고 순차적으로 스택에 변수를 push하는 모습을 볼 수 있다!!
	*/
	~Test() {
		cout << "Destory Test Class Constructor function (Second declared Class)" << endl;
	}
	int nData;
	void Print() {
		cout << nData << endl;
	}
};

class Global {
public:
	Global() {
		cout << "Call Global Class Constructor function" << endl;
	}
	~Global() {
		cout << "=============================================" << endl;
		cout << "Destory Global Class Constructor function((Finally declared Class))" << endl;
	}
};
class Global_G {
public:
	Global_G() {
		cout << "Call Global_G Class Constructor function" << endl;
	}
	~Global_G() {
		cout << "=============================================" << endl;
		cout << "Destory Global_G Class Constructor function((Finally declared Class))" << endl;
	}
};

class MallocTest {
	public:
	MallocTest() {
		cout << "Call MallocTest Constructor function" << endl;
	}
	~MallocTest() {
		cout << "=============================================" << endl;
		cout << "Destory MallocTest Class Constructor function(MallocTest declared Class))" << endl;
	}

};

void PrintUserData(USERDATA * nStructData) {
	printf("PrintUsreDat Function %d , %s\n", nStructData->nAge, nStructData->szName);
	cout << nStructData->AddToAge(nStructData, 100) << endl;
}

int AddUserData(USERDATA *nStructData,int nParam) {
	cout << "CAll AddUserData Function" <<'\t'<< nStructData->szName << "Struct" << endl;
;	return nParam + nStructData->nAge;
}

Global globalClass;
UserClass g_newUserClass;
Global_G g_globalVar;
int main(void) {
	USERDATA host = { 33, "Host" };
	USERDATA user = { 20,"철수",AddUserData,PrintUserData};

	printf("%d %s \n", user.nAge, user.szName);

	user.PrintValue(&user);
	cout << user.AddToAge(&host, 100) << endl;
	std::cout << "Struct Member" << std::endl;

	UserClass UsedUser = { 20,"New User" };
	UserClass UsedHost = { 33 , "New Host" };
	UsedUser.Print(&UsedUser);
	UsedUser.Print2();
	UsedHost.Print2();

	std::cout << "Class Member" << std::endl;

	Test testClass = Test(1000);
	testClass.Print();

	Test* newTestClass = new Test(9999);
	newTestClass->Print();

	//malloc을 사용하여 생성자 함수가 실행 될까??
	//밑에 malloc을 통해 메모리 주소를 담을수 있는 공간을 만든 거지 MallocTest Class를 사용한것은 아니다
	//Class를 sizeof를 통해 크기를 찾아 봤을때는 Class안의 멤버 변수가 크기를 담당하지 메소드는 메모리크기에 잡히지 않는다!!
	MallocTest* mallocTest= (MallocTest*)malloc(sizeof(MallocTest));
	free(mallocTest);
	MallocTest* n_mallocTest = new MallocTest;
	delete n_mallocTest;
	cout << "UserData Sizeof : "<<sizeof(USERDATA) << "UserClass  Sizeof :" << sizeof(UserClass) << endl;
	std::cout << "Constructor Class" << std::endl;
	std::cout << "End Main function" << std::endl;

	return 0;
}