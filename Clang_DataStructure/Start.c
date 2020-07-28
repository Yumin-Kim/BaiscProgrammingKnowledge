#include <stdio.h>

int main() {
	int nResult = 10;
	for (int i = 0; i < 100; i++)
		nResult = 100;
	printf("%d", nResult);
	return 0;
}