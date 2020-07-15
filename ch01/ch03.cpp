#include <stdio.h>
/*
상식 파일 입출력 IO 관련은 kernel해주는것 꼭 명시 하기!!
C언어에서 입출력을 담당하는 함수를 사용하게 되는데 그 함수로 인해서 개발자가 입출력을 담당하고 있다고 생각함
C언어에서 입출력을 담당하는 함수들은 입출력을 요구를 할뿐 직접적으로 입출력을 담당해서 정보를 보여주거나 쓰지 않느다!!

입출력을 담당하는 파일은 두가지 Buffer가 존재하는데  write , Read 용으로 Buffer(즉 메모리!!)가 존재 한다

예시
응용프로그램을 실행하고 있지 않을때 키보드를 입력하게 되면 어떨게 되나??
kernel자체에서 키보드 입력에 대해서 Input을 처리하는 소프트웨어가 없을때 kernel 내부에서 버림!! 줄곳이 없기 때문에
Input값을 받을 소프트웨어가 있으면 그 소프트웨어의 Buffer에 담기게 한다!!

예시
Input을 담당하는 소프트웨어가 있을때 무한정 입력을 하게 된다면??
어느정도의 Buffer에 담기다가 담을 공간이 없게되면 삑삑 소리가 나게 되는데 kernel에서 담을 Buffer의 공간이 없다고 신호를 주는것이다!!

파일의 송수신은 kernel에서 담당하고 가지고온 정보의 I/O를 담당하는 File은 Write ,Read할 Buffer를 준비하고 그 버퍼안의 문자열을 퍼올리는(요구하는) 행위를 getchar , putchar에서 담당하고 있다!!
Buffered I/O 라고 말한다!!
이와 같이 Buffer를 통해 write,read의 임무를 수행하는 함수는 getchar , gets , scanf 가 있다
getchar는 버퍼에서 한글자만 퍼올림!!
gets 는 개행문자 즉 한줄만 퍼올림!!
scanf는 형식(자료형)에 따라 퍼올린다!! 

반대로 None Buffered I/O가 있으며 입출력 하드웨어 잧이나 예외 상황이 발생하여 처리 가 필요한 인터럽트를 발견하고 buffer를 거치지 않고 비로 read.Write임무를 수행하는것을 말한다
대표적인 메소드로 _getch 함수가 있다!! 콘솔입력을 사용하기 때문에 기존에 쓰던 stdio.h가 아닌 conio.h를 include를 해야한다!!

fflush() Buffer를 비우는 함수이며 out의 Buffer만 비우게 된다!!

버퍼를 사용하지 않게 된다면??
프로그램과 운영체재는 데이터를 효율적을 관리하기 위해 입출력 버퍼를 사용하게되는데 버퍼를 사용하지 않게 된다면 데이터를 1바이트씩 입력이 일어날때마다 매번 데이터를 처리 하기위해
테이터를 처리하기위해 cpu를 사용하게 되는데 

입출력 버퍼에 데이터를 저장하는 행동을 버퍼링(buffering)이라고 부릅니다.

putchar("\n"); 
"\n"하게 되면 char[]으로 인식하고 주소를 받아 오게 되어서 읽어 오지 못한다!!
이 문제를 해결하기 위해서는 '\n'을 사용하여야 하고 ''사용하게되면 char형태로 받아오기 때문에 출력이 가능하다!!

Debug
중단점 생성은 F9
디버깅은 F5
F10 누르게 되면 중단점에서 다시 실행된다 , 한줄씩 실행할 수 있게 해줌!!
>> 이 밑에  예제를 보게되면 CC라고 채워진 칸이 asc code의 숫자 값이 들어 가는것을 볼 수 있다!!

메모리의 주소 값이 계속 바뀌는 이유!!
win7부터 ASLR이 도입되었는데 Address Space Layout Randomization

표준 입출력도 하나의 파일 입출력인가??
애매하지만 뜯어 보면 하나의 파일 입출력이라고 할 수 있다
키보드에서 입력을 받아 console(CMD 화면)로 추상화 되어 키보드로 입력 받은 값을 출력 할 수 있기 때문에!!

scanf_s 사용시 사용자가 300을 입력했을때 문자열로 인식을 하는데 개발자는 %d로 읽어 오라는 명령을 통해 정수형을 읽어 올때까지 실행된다!!



*/
int main(void)
{

	char szName[12] = { "Hello" };
	//gets_s(szName,sizeof(szName));
	
	//double
	printf("%f\n", 123.456);
	
	//float 
	printf("%f\n", 123.456F);

	//표준 입출력
	int user_Age = 0;
	printf("나이를 입력하세요 : ");
	scanf_s("%d", &user_Age);

	getchar();
	//fflush(stdin);

	char user_Name[12] = { 0 };
	printf("이름을 입력하세요!! : ");
	gets_s(user_Name, sizeof(user_Name));
	//scanf_s("%s", &user_Name);

	printf("%d , %s \n", user_Age, user_Name);

	return 0;
}