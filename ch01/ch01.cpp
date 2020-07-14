/*

절차지향 언어
일반적인 절차 지향 언어 특징code가 덩어리를 이루게됨 이런 덩어리를 함수로 만듬
프로그램의 규모가 커질수록 기능에 따라 분리 할 필요가 있음

객체 지향 언어
객체 지향으로 전환 하기 위해서 여러 객체간의 관계를 이해하고 상호작용하는것들을 이해 해야한다

중점은 class >> 함수와 구조체를 섞은것과  흡사 하다
           -----------------------------------------
           |  추상 <<비슷한 의미로<< 개념 << 설계  |  
           |  ^^^^^                 ^^^^^^         |
           |  설계                   구현          |
           -----------------------------------------
            >>JAVA에서 볼 수 있음 (abstract class)
이와 같이 개념과 구현이 분리되어 있고 개념적인 부분을 Class로 비유할 수 있다
객체 지향은 class와 구현의 분리하고자 하는 특징을 가지고 있다
>>언어 구조에 녹아있음

Tip
file 열고 닫는 행위(I/O) 이와 같은 행위를 장치 제어 라고 한다

*/


#include <iostream>

int main()
{
    printf("Hello World");
    /*
    << redirect의 의미로
     dir > tex.txt 면  현재 디렉토리 내용을 tex.txt파일에 담게된다
     dir >> tex.txt 하면 기존에 있던 내용에 append하게 된다
     >> 의미는 redirect로 이동시킨다는 의미로 비유 할 수 있다
    절차지향(C언어)는 모든 함수 자체를 알아야 하고 전적으로 프로그래머의 생각되로 동작한다
    객체 지향에서는 행위 주체와 이용 주체가 존재하며 분리한다(알아서 작동한다)
    결론적으론 구조가 간결해진다
    세부적인 디테일은 나중에!!
    std namespace
    :: 범위 지정 연산자
    인스터스(Instance)
    int nData; 
    nData는 int형식에 대한  인스턴스(비유하자면 예시) 이다
    하나의 예시가 된다고 생각!!
    
    std의 설명
    std namespace에 속한 cout객체는 iostream 클래스의 인스터스(혹은 객체)입니다!!
    namespace 비유하자면 소속라고 비유 할수있다
    분류,묶음으로 비유 가능!!

    C언어에서는 printf("안에 데이터 형식을 집어 넣어야한다")
    하지만 C++에서는 std::cout<<123<<"123" 사용시
    std::cout에 있는 cout이 알아서 데이터 형식을 찾아서 찍어준다

    자료형이란
    자료형의 일정 크기의 메모리에 저장된 정보를 해석하는 방법!!
    auto 중요!!(자동 변수 원본의 자료형을 따라 간다)


    변수 선언 & 정의
    int a = 10;  C언어 스타일
    int b(10); C++언어 스타일

    C++ 변수 선언(모든 변수 선언이 성립한다)
    int a(10);
    int b(a);
    int(10);컴파일 단계에서 상수로 변환된다

    다시 malloc 복습!!
    malloc(size_t()) 오직 크기에만 신경씀!!
    주소를 반환,확보하는 것만 생각하는데 용도에는 관심이 없다!!
    os의 패라다임 변화(Ram 기능 향상및 os발전!!)
    메모리를 가상메모리로 할당하게된다
    결론 메모리를 허가 받아서 사용하기 때문에 malloc을 통해 메모리 할당을 실패할일은 없다!!
    C++
    malloc은 원래 성공 또는 실패로 결과값을 만들게 되는데 개발자들은 거의다 성공할것이다라는 인식으로 인해서 C++에서는 new라는 연산자가 생기게된다!!
    new 연산자
    1.malloc의 메모리 동적 할당의 역할은 동일!!
    2.new Class외 같이 자료형을 class로 적게되면 class의 생성자 함수를 호출한다
    문법은 밑에 참고!!

    참조자!!!
    참조자를 쓰는 이유는??
    포인터를 쓰는이유부터 알아야 한다!!
    변절???
    포인터 자체가 변수이다 ( 변할수 있다!! 변함에 의해 값이 변할수 있다!! )
    변하지 않는 포인터를 만들기 위해 사용!!
    팁
    포인터를 사용하는 이유!!
    1.함수가 여러 개로 나뉘거나
    2.배열과 같은 자료형을 통째로 함수에 전달하는것이 아니라 포인터를 통해 주소값을 전달하여 연산 진행!!
    */
    std::cout << "This C language lecture!!!!\n" << 123 << "HEllo\n";

    //C
    int* pnData = (int*)malloc(sizeof(int));
    free(pnData);
    //C++
    int* pnData_ = new int;
    delete pnData_;

    //배열 같은 경우 동적할당후에 제거하는 방법!!

    //C array!!
    int* pnArray = (int*)malloc(sizeof(int) * 5);
    free(pnArray);
    //C++Array!!
    int* pnArray_ = new int[5];
    delete [] pnArray_;


    //참조자는 `별명`이다!!

    int a = 10;
    int* ptr_a = &a;
    std::cout << *ptr_a;

    int nData(10);
    std::cout << nData << std::endl;

    int& rData = nData;
    rData = 100;
    std::cout << &nData << std::endl;
    std::cout << &rData << std::endl;
    std::cout << rData << std::endl;


}
