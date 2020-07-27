#include <stdio.h>
//callback , 어셈블리 코드 분석!!
//배운거 복습위주!!
//연령에 따라 가격비교
//가격비교를 하고 각기 다른 동작을 한다고 했을때 함수 포인터와 lookupTable의 쓰임이 맞다!!

//레지스터 >>  calling convention , 디스 어셈블리어 >> callback

int CheckPrice(double *Table ) {
	return 0;
}
void PrintService_1(int nServiceNum) {
	printf("1 번 서비스 입니다 :\n");
}

void PrintService_2(int nServiceNum) {
	printf("2 번 서비스 입니다 :\n");
}

void PrintService_3(int nServiceNum) {
	printf("3 번 서비스 입니다 :\n");
}

void PriceOfAgeCompareFunc_Age0(int nAge,double * Table)
{
	int ncustomer = 0;
	void(* pszServiceFunc[3])(int) = {
		PrintService_1,PrintService_2,PrintService_3
	};
	printf("나이는 %d , 가격값은 : %d\n",nAge , (int)(Table[nAge] * 1000));
	printf("회원이면 1,아니면 0 : ");
	scanf_s("%d", &ncustomer);
	if (ncustomer == 1) {
		int nServiceNumber = 0;
		printf("이용할 수 있는 서비스가 1에서 3번까지 있습니다\n확인하시려면 번호를 , 원하지 않으면 -1 : ");
		scanf_s("%d", &nServiceNumber);
		printf("%d", nServiceNumber);
		nServiceNumber < -1 || nServiceNumber > 3 ? printf("저희서비스는 1에서 3번까지밖에 존재 하지 않습니다\n") : pszServiceFunc[nServiceNumber](10) ;
	}
	printf("감사합니다!!\n");
}
#define ADD(a,b)	(a+b)

int __inline Add(int a , int b) {
	return a + b;
}

int multiply(int a , int b) {
	return a * b;
}

int main(void) 
{
	//1세부터
	double nPriceTable[10] = {
		0.2,0.25,0.27,
		0.3,0.35,0.37,
		0.6,0.77,0.8,
		0.94
	};
	int nInput = 0;
	printf("ADD macro : %d \n", ADD(10, 20));
	printf("add __inline : %d \n", Add(10, 20));
	printf("multiply __inline : %d \n", multiply (10, 20));
	/*
	while (1) {
		printf("아이의 연령의 입력하세요->>미만으로 입력해주세요(1살이면 0살!!)(종료 -1) : ");
		scanf_s("%d", &nInput);
		//Looktable사용을위해 1뺀다
		if(nInput < 0) 
		{
			printf("0살은 무료입니다!!\n");
			break;
		}
		else
		{
			printf("입력하신 나이는 :%d\n", nInput);
			PriceOfAgeCompareFunc_Age0(nInput, nPriceTable);
		}
	}
	*/
	return 0;
}