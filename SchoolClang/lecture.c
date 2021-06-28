# include <stdio.h> //전처리기 stdio.h 라이브러리 포함하겠다
//변수 ram에 할당한다
//visual stdio에서는 자체적으로 모든 파일을 build 하기 때문에 파일 우클릭후에 속성에서 빌드 제외를 선택하면 main 함수를 중복되게 파일을 생성 할 수 있다
//int 32bit >> 4byte >>구성 00000000 00000000 00000000 00000101 >> int a = 5;
//8bit = 1byte >> 컴퓨터에서 데이터를 처리하는 가장 작은 단위

int main() //C프로그램이 자체 적으로 실행하는 파일
{
	int num1 = 241;
	int num2 = 32;
	printf("%c \n ", 'a');
	printf("%c \n ", 'aasd');
	printf("%s \n", "hello world");
	printf("%g \n", 3.1234123124124);
	printf("%.3g\n ", 3.1234123124124);

	int a; char b; float c; double d; char str[100] ="Hello world";
	//sizeof 자료형의 크기를 알려준다 byte로 표현
	printf("%d %d %d %d %d \n", sizeof(a), sizeof(b), sizeof(c), sizeof(d) , sizeof(str));

	//형변환 (자료형을 적어 준다)sum >> 자료형이 큰걸로(범위가 큰걸로 형변환 ) 형변환을 해준다
	int sum = num1 + num2 + 7;
	double division = (double)sum / 3;
	printf("%f \n", division);

	printf("%c\n", 97);//ASCode로 숫자 == 문자 >> 97 >> a변환 

	char str1;
	scanf("%c", &str1);

	printf("%c %d", str1, str1);

	/*
	//입력 받기 >> _CRT_SECURE_NO_WARNINGS 속성에 전처리기 정의 안에 추가해야지 scanf_s 안쓰고 작동한다
	//scanf 사용시 다른 문자열은 같이 적지 말것
	int scanf_num1, scanf_num2;
	printf("정수 입력");
	scanf("%d %d", &scanf_num1, &scanf_num2);

	printf("출력 : %d %d\n", scanf_num1, scanf_num2);

	float scanf_flo1, scanf_flo2;
	printf("실수 입력");
	scanf("%f %f", &scanf_flo1, &scanf_flo2);

	printf(" %f ,%f \n ", scanf_flo1, scanf_flo2);
	*/
	return 0;
}