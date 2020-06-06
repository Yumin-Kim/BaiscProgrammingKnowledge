#include <stdio.h>

void asterisk(int num) {
	if (num > 1) {
		asterisk(num / 2);
		asterisk(num / 2);
	}
	printf("* %d > ",num);
}

int main() {
	asterisk(4);
}