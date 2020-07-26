#include <stdio.h>

/*
제어문
다중 조건문(다중 if, switch..case)은 성능적인면으로 보아서 비효율적인 면이 있기때문에 리펙토링을 도입해야한다!!(아직까지는 모듈화밖에 생각안남)
조건문을 사용할때 트리 구조를 생각해서 프로그래밍해보기!!

switch(실수)
실수 작성시 부동 소수점의 오차로 인해서 컴파일 자체가 이루어 지지 않는다!!
*/


int main(void) {

	int alist[5] = {0};
	printf("%d\n", sizeof(alist));
	printf("%d\n", 20);

	int user_Input = 0;

	printf("기계어로 변형되는것을 확인해보자!! 숫자 입력!! : ");
	scanf_s("%d",&user_Input);
	if (user_Input > 10) {
		user_Input = 100;
		if (user_Input > 50) user_Input = 1000;
	}
	/*
		sizeof는 컴파일러와 관계가 있다!!
		6번,7번의 결과는 똑같다!!
		왜 똑같은지를 확인하기 위해서 기계어 >> 디스 어셈블리어 코드를 보게되면 변환되어가는 모습을 알 수 있다!!
	*/
	//goto 문
	/*
		밑에 있는 goto를 코드를 통해 알아볼 수 있듯이 문자열을 입력 받지 못하게 되면 예외 처리를 할때 잘 사용되면 
		평상시에는 잘 횔용 되지 않는다!!
	*/
	//break , continue
	/*
		break 는 반복문을 종료함!!
		continue는 반복문을 계속하는데 시작 부분으로 점프한다!!
		하지만 continue를 안쓰는게 좋음!!
		제어 로직의 흐름이 겹침 현상이 일어난다(가독성면에서도 좋지 않았다!!) >> 흐름의 복잡해진다!!
	*/


	int nAge = 0;
	printf("나이를 입력하세요!! : ");
	scanf_s("%d", &nAge);

	if (nAge < 0) {
		goto ERROR;
	}
	printf("나이 출력 : %d \n", nAge);
	return 0;
ERROR:
	puts("ERROR");
	return -1;
}
