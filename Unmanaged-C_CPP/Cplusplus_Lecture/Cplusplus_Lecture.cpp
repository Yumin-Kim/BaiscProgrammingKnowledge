#include <iostream>
/*
객체와 인스턴스의 차이
Class Car{
    ...
}

Car tice; 객체만 선언했을뿐 어떠한 메모리더 차지 하지 않고있다
Car matize = new Car(); 클래스의 인스턴스를 만들었고 메모리가 객체이 의해 차지되었다 즉 메모리에 올라가는 동시에 실체화가 되었다고 생각!!

*/

void TestFunc(int number ,const char * pszData) {
    printf("%s\n",pszData);
}

int main()
{
    int nData(10);
    int nPData(nData);
    //참조자 변수 이며 nData와 rData의 값 , 주소 똑같다!! 또 다른 별명을 지어 주는것과 같다
    //포인터를 상수화 시킨것과 의미가 같다!!
    int& rData = nData;
    rData = 100;
    int(10);
    char nString[13] = "Hello World";
    auto nCpyString(nString);

    auto psTestFunc(TestFunc);
    psTestFunc(12,"Hello");
    //가능한 이유는 함수또한 메모리 주소를 가지기 때문에 가능하다!!
    void(*psFunc)(int,const char*) = TestFunc;

    psFunc(13, "HelloWorld");

    int* pszData = (int *)malloc(sizeof(int)*5);
    free(pszData);
    int* psznewData = new int[5];
    delete [] psznewData;

    int a = 10;
    int* const psz = &a;
    int& pszNew = a;
    int b = 20;
    int c = 30;

    *psz = 100;
    //*psz = &b;
    pszNew = 300;
    //pszNew = &c;
    std::cout << nString<<"\t" << nCpyString << "\t" << sizeof(nString)<<"\t" << sizeof(nCpyString) << std::endl;
    std::cout << nData << std::endl;
    std::cout << "Hello World!\n";
}

