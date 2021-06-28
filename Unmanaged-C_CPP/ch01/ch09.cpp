#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*
Memory 구조 가상 메모리부름!!
stack 크기가 1MB , 일반적인 변수가 담김
heap 자유 메모리 영역(32bit임을 가정하면 1.7GB) , 동적 할당시 담김 . 접근 permission : Read & Write & 실행!! 
code(text)영역 :  
data : 두가지 영역으로 분리 Read & Write(전역,정적 변수가 담긴다) , Read(문자열 상수가 담긴다!!) 되는 영역이 따로 있다!!

이런 메모리는 OS가 관리한다!!
예를 들어 image를 변수에 담을려고 하는데 image의 크기가 20MB로 메모리의 스택영역의 1MB로는 부족하여 OS한데 20MB가 필요하다고 요청한 후에 OS는 20MB를 허가해준다!!
다쓴후에는 OS한데 반납해야한다!!
허가는 동적할당의 할당을 의미하고 할당(허가)를 받으면 반납을 무조건 해주어야한다!!

일반적으로 우리가 선언하는 변수는 자동변수라고 한다!! 자동으로 관리가 되기때문에!!
할당(허가)을 받게되면 void *형식으로 개발자에게 전달 되게 된다!!

*/
int main() {

	int* plist = NULL, i = 0;
	//malloc 은 void* 이기때문에 type casting을 하기 위해서 int * 을 한것이고 사이즈 또한  할당 받기위해서 원하는 크기를 인자값을 추가 하였다
	plist = (int*)malloc(sizeof(int)*3);
	memset(plist, 0, sizeof(int) * 3);

	plist[0] = 10;
	plist[1] = 20;
	plist[2] = 30;
	for (i = 0; i < 3; i++)
	{
		printf("%d \t", plist[i]);
	}
	/*
	변수만 적었는데 왜 free함수로 인해서 메모리가 해제되는이유는??
	동적 메모리를 할당받은 주소 위와 마지막 뒷부분에 fdfdfdfd 이런식으로 메모리가 채워져 있는모습을 볼 수 있다!!
	Debug모습에서만 볼 수 있다!!
	fd의 용도는 밑에 문자를 fd안에 집어 넣고 빌드시 Heap안 Buffer overflow가 발생해서 에러가 난다
	에러를 보아 fd는 동적 메모리 할당의 경계를 보여주고 침범하게 될시 에러를 발생시킨다!!
	이런 에러 현상은 free함수 코드를 실행 시키게되면 발생한다!!
	*/
	//*(((char*)plist) + 12) = 'A';
	printf("Memory size: %d\n", _msize(plist));

	//_msize()의 함수로 보아 free함수에 sizeof 나 자료 형을 기입할 필요가 없는 것을 알게 되엇다!!

	free(plist);
	printf("Hello\n");

	return 0;
}