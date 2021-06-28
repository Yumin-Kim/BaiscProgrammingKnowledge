#include <stdio.h>
#pragma warning(disable: 4996)
int main() {
	char* apszList[3] = { "Test","String","Data" };
	char szBuffer[32] = { "Testing" };
	char* pszBuffer = szBuffer;
	char** ppBuffer = apszList;
	printf("%c\n",*apszList);
	printf("%c\n",*pszBuffer);
	printf("%s\n",apszList[0]);
	printf("%s\n",*(ppBuffer+1));
	return 0;
}