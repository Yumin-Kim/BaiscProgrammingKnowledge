#include <stdio.h>

int main() {
	int arr[2][3] = { { 1,2,3 } , { 4, 5, 6 } };
	
	for (int(*row)[3] = arr; row < arr + 2; row++) {
		for (int(*col) = *row; col < *row + 3; col++) {
			printf("%d ", *col);
		}
		printf("\n");
	}

	char string[3][10] = { "Hello" , "Example" , "Doument" };
	char* ptr_str[3];

	for (int i = 0; i < 3; i++) {
		ptr_str[i] = &string[i];
	}

	for (int i = 0; i < 3; i++) {
		printf("%s ", ptr_str[i]);
		printf("%d ", *ptr_str[i]);
	}

}