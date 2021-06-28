#include <iostream>
using namespace std;


void PrintAddress(int &ptr) {
	int n_nData = 100;
	cout << &ptr << endl;
}

int main() {

	int nData = 10;
	PrintAddress(nData);

	return 0;
}