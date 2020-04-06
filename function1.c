#include <stdio.h>

void printArr(int (*arr)[3]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void reversNum( int *a , int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void recursiveFunc(int a) {
	if (a > 25) {
		return;
	}
	printf("%d\n", a);
	recursiveFunc(a +1);
}
void rec(int num);

void print_noSpace(char* str) {
	int i = 0;
	printf("%d \n", 100000);
	while (1) {
		if (str[i] == '\0') {
		printf("%c \n", str[i]);

			printf("%d \n", i);
			return;
		i++;
		}
	}
}

int main() {

	int arr[2][3] = { {1 ,2,3},{4,5,6} };
	int a = 10;
	int b = 20;

	printArr(arr);
	reversNum(&a, &b);
	printf("a = %d , b = %d", a, b);
	recursiveFunc(a);

	rec(5);

	print_noSpace("Hello , World\n");
	print_noSpace("My name is Clanguage\n");

	return 0;
}

void rec(int num) {
	if (num == 0) return;
	printf(" >>> %d \n", num);
	rec(num - 1);
	printf("num-1 ÈÄ>>> %d \n", num);
}