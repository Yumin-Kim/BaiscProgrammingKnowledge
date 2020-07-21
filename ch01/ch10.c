#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*
pointer 11장 5,6 다시 보기!!
다중포인터와 배열의 배열
*/
int main() {
	char szSrcBuf[12] = { "Hello" };
	char szDstBuf[12] = { 0 };

	char* pszData = (char *)malloc(sizeof(char) * 12);

	//Deep copy (주소 값이 아닌 해당하는 주소에 담긴 값을 복사한다)
	memcpy(szDstBuf, szSrcBuf, sizeof(char) * 12);
	//shallow copy (얕은 복사로 문자열이 담긴 주소값을 복사 )
	pszData = szSrcBuf;

	printf("%s\n", pszData);
	//shallow copy로 인해서 동적할당 받은 변수를 free할려해도 할당 받은 주소값을 모르기 때문에 에러가 발생 한다
	//free(pszData);

	char szBuffer[12] = { "I am a boy." };
	char* pszFound = strstr(szBuffer, "am");
	int nIndex = pszFound - szBuffer;

	printf("%p\n", szBuffer);
	printf("%p\n", strstr(szBuffer, "am"));
	printf("%p\n", strstr(szBuffer, "boy"));
	printf("%d\n", nIndex);

	int alist[10] = { 0 };
	//컴파일러가 해석하는 순서
	//*plist부분을 먼저 확인 하여 1. 포인터 변수이다를 확인하고 자료형이 무엇인지 확인!!

	//포인터의 배열과 다중포인터 !!
	//직접 지정!! 주어진 stack영역이 맞다면 이와 같이 성립한다!!
	*((int *)0x0019FE48) = 10;
	char* nTextObj[3] = { "Hello","World","Next" };
	//위와 같이 선언하면 []부터 해석하고 그다음 *을 해석후 자료형식을 분석한다!!
	//static을 사용하개되면  전역 변수처럼 사용할 수 있다 >> 하지만 동시성의 문제가 있기때문에 사용하지 말것!!

}