#include <stdio.h>
/*
구조체는 여러 자료형을 모아둔 개발자가 만든 하나의 자료구조이다!!
*/
typedef struct UserData {
	int nHeigit;
	char nName[12];
	char szPhone[12];
	char gender;
	struct USERDATA* pNext;
}USERDATA;

int main() {
	USERDATA userDictonary, *stmep;
	USERDATA  me;
	me.nHeigit = 180;
	me.gender = 'M';
	strcpy_s(me.nName,sizeof(me.nName),"Hello_Hello");
	strcpy_s(me.szPhone,sizeof(me.szPhone),"1234-1234");

	char buffer[sizeof(USERDATA)];
	USERDATA* pData = (USERDATA*)buffer;
	pData->nHeigit = 180;
	pData->gender = 'M';
	strcpy_s(pData->nName, sizeof(pData->nName), "World_World");
	strcpy_s(pData->szPhone, sizeof(pData->szPhone), "789-1234");

	userDictonary.pNext = &me;
	me.pNext = pData;
	pData->pNext = NULL;
	stmep = &userDictonary;
	while (stmep != NULL) {
		printf("UserData Name : %s ,PhoneNumber: %s ,Height: %d , Gender : %c \n", stmep->nName, stmep->szPhone, stmep->nHeigit, stmep->gender);
		stmep = stmep->pNext;
	}

	return 0;
}
