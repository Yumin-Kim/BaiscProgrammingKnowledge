#include <stdio.h>

void aa(int a ) {
	if (a > 1) {
		aa(a / 2);
		aa(a / 2);
	}
	printf("%d\n", a);
	printf("\n*");
}

int main() {
	aa(5);
}