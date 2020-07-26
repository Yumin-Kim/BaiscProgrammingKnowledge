#include <stdio.h>

/*

팁 : 컴퓨터는 2의 보수를 체계를 사용!!
2의 보수를 구하기 위해서는 1의 보수를 취한후 1을 더한다!!

int a  =  3;
l-value  r-value
변수     상수
l의미는 location(위치선정을 의미한다 >> 변수의 자리이며 변수는 메모리 주소값을 가지는 이름으로 의미는 상통한다!!) , left의미를 지니고 있다
r의미는 right의미한다


type promotion (형승격)
이형 자료 간의 계산
'A' + 1 >> int 형으로 반환한다!!
자료형을 표현하는 범위가 큰형식을 따라 간다!!
그래서 int로 된다!!

이와같이 type promotion으로 int으로 값을 반환하는 경우가 많아서
putchar(int형을 적으라고 한다)

비트연산 사용이유?
비트마스크를 하기 위해서 사용!!
8bits연산(전기 스위치를 예를 들면 스위치하나를 1bit라고 하며)전기 스위치를 작동시킬때 주로 사용한다!
비트마스크란 컴퓨터의 언어인 이진수를 활용하여 정수를 이진수 형태로 표현하여 비트연산을 활용하는 방법입니다.
예시로는 ip주소에서 network ID값만 알아내는 경우!!
ip주소는 network ID , Host로 구성되어 있는데


*/


int* convertSecond(int second) {
	int elementsArray[6] = { 0 };
	if (second % 60 != 0) {
		elementsArray[0] = second % 60%10;
		if (second % 60 > 10) {
			elementsArray[1] = second % 60 / 10;
		}
	}
	if (second / 60 != 0) {
		if (second / 60 > 59) {
			elementsArray[4] = second / 3600 % 10;
			if (second / 3600 % 10 > 9) {
				elementsArray[5] = second / 3600 / 10;
			}
		}
		if (second / 60 % 60 != 0) {
			elementsArray[2] = second / 60 % 60 % 10;
			if (second / 60 % 60 > 9) {
				elementsArray[3] = second / 60 % 60 / 10;
			}
		}
	}
	return elementsArray;
}

int main(void) {
	int nData;
	nData = 3; // copy & Overwrite를 의미한다

	const int nData_1 = 10; //형 안정화!!
	//nData_1 = 100;lvalue가 상수화된 객체로 대입되었습니다!!

	/*
	누적을 하기 위해서 초기화는 필히 해주어야한다!!
	초기화 하지 않고 누적 하게 된다면 개발자가 생각하는 원하는 값은 나오지 않는다!!
	int nTotal;
	nTotal += 1;
	nTotal += 2;
	nTotal += 3;
	*/

	putchar('A'+1);
	printf("\n");
	printf("%d\n", 3 );
	printf("%d\n", ~3 + 1 );
	//~을 통해 1보수로 취한후에 1을 더하게되면 -3이 된다!!

	int input_one = 0;
	int input_two = 0;
	//scanf_s("%d%d", &input_one, &input_two);

	//printf("%0.2f\n", (float)(input_one+input_two)/2);

	int second = 0;
	printf("원하는 초를 입력해주세요 : ");
	scanf_s("%d", &second);
	int* convertValue = convertSecond(second);

	printf("%d초는 %d%d시간 %d%d분 %d%d초입니다!!\n",second,convertValue[5], convertValue[4],convertValue[3],convertValue[2],convertValue[1],convertValue[0]);

	printf("Hello Ch04");
	return 0;
}