#include <stdio.h>
/*
포인터와 메모리
실습시 속성 >> 링커 >> 고급 임의주소 설정 풀고 실습하기!!

300을 16진법으로 표현하게되면
0x00 00 01  2C
메모리에 표현되는 방식은
2C 01 00 00
이와 같은 방식을 Byte Order이며 위와 같이 작은 수 부터 오는 방식을 Littile Endian 방식이다!!
Little Endian 방식을 체택한 곳은 intel!! 
현 cpu가 intel로 컴파일 되어서 Little Endian 방식으로 메모리에 담긴다!!

변수는 메모리로 구현되었다!!
모든 메모리는 주소를 가지며 &연산자를 활용하영 주소를 확인 할 수 있다!!
&는 compile Time의 연산자이다!!
한번 compile 된후로는 신경쓰지 않는 연산자이다!!

위와 같은 설명은 직접 지정 (메모리를 직접 지정 했다는 의미이다)

간접 지정!!
포인터 활용!!
밑에 예제를 디버깅한것으로 보게되면 npnData의 주소값은 nData와 다른것은 그전에 알 수 있고
npnData의 메모리의 값에는 nData의 주소값이 Little Endian 방식으로 들어가는것을 볼 수 있다

한번더 강조!!
포인터를 사용하는이유??
함수의 배열을 전달하는 부분에서 포인터의 사용이 극대화 된다!!
함수가 여러개로 분리되어도 효과는 극대화된다!!

우리가 사용하는 메모리는 virtual Memorry를 사용하고 있다!!

*/
int main() {

	int nData = 300;
	int* pnData = &nData;
	//메모리의 주소값 변경!! int의 크기 만큼 결과적으로 nData의 주소값에서 8byte정도 뒤에 있는 메모리의 주소값으로 이동하게된다1!! 
	pnData += 2;
	//변경된 메모리 주소에 300이란 숫자가 16진법으로 변형후 Little endian방식으로 추가된다!!
	*pnData = 300;

	//포인터를 활용한 직접 지정하는 방법!!
	*((int*)0x0019FED8) = 100;

	int aList[4] = { 1,2,3,4 };
	int* paList = aList;
	/*
	paList[4] = 10;
	*(paList + 1) = 100; //paList[1]과 같은 의미이다!!
	*/
	int bList[5] = { 40,20,50,30,10 };
	int nTotal = 0;

	for (int i = 0; i < 5; i++)
		nTotal += bList[i];
	printf("%d\n", nTotal);

	nTotal = 0;
	int* pnData_ = bList;
	while (pnData_ < bList + 5) {
		nTotal += *pnData_;
		pnData_++;
	}
	printf("%d",nTotal);
	return 0;
}