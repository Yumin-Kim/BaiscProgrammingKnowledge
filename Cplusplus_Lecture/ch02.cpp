#include <iostream>
/*

��ü�� ������� �׿� ���õ� �޼ҵ���� �𿩼� �̷� �ϳ��� �ٷ��̴�
Ŭ������ C�� ����ü���� Ȯ��� ���� ��ü �Լ��� ������ �ϳ��� Ʋ�̴�

����� ��ȯ�� �ʿ��ϴ�
�ݵ�� �ټ��� (�������� Ŭ������ ������ ����ϴ� ) ����ڸ� ����ؾ��Ѵ�

�� �ǰ��ϰ� ������ �ڵ带 ������? �̷� ������ �� �� ������ ������ �ڵ带 �ۼ��Ҷ��� �ټ��� ����ڸ� ���ο� �ΰ� �۾��ؾ��Ѵ�!!

��ȯ �Ŀ��� ������� ���Ǽ��� �ش�ȭ�ؾ� �ϸ� ������� �Ǽ� ���ɼ��� �����ڰ� �����ؾ��Ѵ�.
C++		C
Class = ����ü + �Լ� + ���� ������ + ���

����� Data , Function(Method)�� ���� �Ǿ� �ִ�
�ܺ�(����ڻ��)���� ����(Class) ����Ҷ� ���� �����ڰ� �ʿ��ϰ� �ȴ�!!

�޴����� �������̽�(��ư , ��ġ)������ ������� ������ ���� �ϴ� �κ��� ���� �� �� �ִ�	

C������ Struct�� ���� �����ڰ� ��� �ϳ��� �ڷᱸ���� �ȴ�
�̷����� ���� �������� ���� ���� ����� ���� 
C++������ �̷� �������� ���� �ϱ� ���� Class������ ���� �����ڰ� ���� �Ѵ�

C : main()�Լ��� ������!!
C++ : main()�Լ��� ���� ���۵����� ���� ���� ������ Class�� ����Ǿ��ٸ� ������ �Լ��� ���� ����ȴ�

*/

using namespace std;
//Class�� �����Ǳ� ���� stuct�� �����ϰ� �ȿ� �Լ� �����͸� Ȱ���Ͽ� ��ü �ȿ��� �޼ҵ�(�������)ó�� ����Ͽ���!!
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
	static int nNumber;

	~UserClass() {
		cout << "=============================================" << endl;
		cout << "Destory UserClass constructor Function (First declared Class)" << endl;
	}
	void Print(UserClass * userStruct) {
		int nData = 5;
		//nNumber = userStruct->nAge;
		cout << "User Name" << userStruct->nName<< "User Age" << userStruct->nAge << endl;
	}
	//������ ���⿡�� Class�� �ּҰ� �ȳѾ�°� ������ ���� ������ �����ϰ� �Ǹ� ���� ������ �޸� �ؿ� Class�ּҰ��� ��� ���� ����� �� �� �ִ�
	//hiden Paramter��� �ϸ� �Լ� ���������� ����� �� �ִ� this �����͸� ����ϸ� �� Ȯ���� �� �� �ִ�
	void Print2() {
		//���������� ���� this�� �޸��ּҸ� ����� �ؼ� �� �� �ִµ� ���������� �Ҵ� ���� �޸� �ּ� 4��° �ؿ� this�� �޸� �ּҰ��� this�� �ȿ� ��� ���� �� �� �ִ�
		int nData = 5;
		//this�� ����ϸ� ������ �ּҰ��� ������!!
		//this�� �ڵ����� ���� �Ǳ⶧���� �����ڰ� �ǵ帱�� ����!!
		//this�� const�� ������ �ٰ� �ִ�!!�׷��� ���� �ٲܼ��� ���� �ٸ��ּҸ� ���� ���� �� ����!!(R-value)�� Ư¡�� �������ִ�
		cout << "this Params " << this << endl;
		cout << "User Name" << nName << "User Age" << nAge << endl;
		cout << "User Name(this Pointer)" << this->nName << "User Age(this Pointer)" << this->nAge << endl;
	}
	/*
		���� ���� ���� �Լ��� ������ش�!!
		Instance�ʹ� ������ ������ �Ѵ�
		class�ȿ� �ҼӵǾ� ������ �ҼӸ� �Ǿ� �ִ� �ǹ̷� Instance�� �ƴϱ� ������ this�� ������� ���Ѵ�!!
		�ؿ� �ڵ�� ���� this pointer�� ����� �� ���� ���� �� �� �ְ� �����Ϸ� ��ü���� ������  ���� �ְ� �ִ�
		��� ���� ���� Static �Լ����� ���� �� �� ����!! >> ���� static ��� ������ public���� �����ϰ� �Ǹ� �׳� ���� ������ �Ǵ°Ͱ� ������ �ǹ̰� �ȴ�!!
	*/
	static void PrintValue() {
		cout << "Call Static Fnuction " << endl;
		cout << "Call Static Fnuction & Access Static memeber Variable " << nNumber << endl;
		//cout << "this" << this << endl;
		//cout << "Call Static Fnuction & Access memeber Variable " << nAge << endl;
	}
};
//Class �ȿ��� static ������ �����ϰ� �Ǹ� ������ ���ǰ� �� �ʿ��ϴ�
int UserClass::nNumber = 100;

class Test {
public :
	Test(int nParam) {
		nData = nParam;
		cout << "Test Class Constructor function" << endl;
	}
	/*
	�Ҹ��� �Լ�!! ���� �ҽ� ~�� ����Ѵ�!! main()�Լ� ������ �ο� ����ȴ�(�� ���� ������ ����Ǿ��� class����!!)!!
	�Ҹ��� �Լ��� ȣ��ȴ°����� ���� ������ ������ ���� ������ ���� �� �� �ִ� 
	(Main�Լ����̳� ���� ���� ���� �������� ����,������ Class�� �Ҹ��� �Լ��� ����ǰ� �״��� ������������ ����,���ǵ� Class �Ҹ��ڰ� ȣ��Ǵ� ����� �� �� �ִ�)
	������ �����ѰͰ� ���� ���α׷��� ���۵ǰ� ���������� ���ÿ� ������ push�ϴ� ����� �� �� �ִ�!!
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
	USERDATA user = { 20,"ö��",AddUserData,PrintUserData};

	printf("%d %s \n", user.nAge, user.szName);

	user.PrintValue(&user);
	cout << user.AddToAge(&host, 100) << endl;
	std::cout << "Struct Member" << std::endl;

	UserClass UsedUser = { 20,"New User" };
	UserClass UsedHost = { 33 , "New Host" };
	UsedHost.nNumber = 100;
	UsedUser.Print(&UsedUser);
	UsedUser.Print2();
	UsedHost.Print2();
	UsedHost.PrintValue();
	std::cout << "Class Member" << std::endl;

	Test testClass = Test(1000);
	testClass.Print();

	Test* newTestClass = new Test(9999);
	newTestClass->Print();

	//malloc�� ����Ͽ� ������ �Լ��� ���� �ɱ�??
	//�ؿ� malloc�� ���� �޸� �ּҸ� ������ �ִ� ������ ���� ���� MallocTest Class�� ����Ѱ��� �ƴϴ�
	//Class�� sizeof�� ���� ũ�⸦ ã�� �������� Class���� ��� ������ ũ�⸦ ������� �޼ҵ�� �޸�ũ�⿡ ������ �ʴ´�!!
	MallocTest* mallocTest= (MallocTest*)malloc(sizeof(MallocTest));
	free(mallocTest);
	MallocTest* n_mallocTest = new MallocTest;
	delete n_mallocTest;
	cout << "UserData Sizeof : "<<sizeof(USERDATA) << "UserClass  Sizeof :" << sizeof(UserClass) << endl;
	
	std::cout << "Constructor Class" << std::endl;
	std::cout << "End Main function" << std::endl;

	return 0;
}