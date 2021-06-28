#include <iostream>


int main() {
	int nData = 10;

	int& rData = nData;
	rData = 20;

	printf("%d\n", nData);

	int* pnData = &nData;
	*pnData = 30;

	printf("%d\n", rData);
	return 0;
}