/*
�ǽ���:Array_Pointer_1 �ǽ�!!
������ ����: �ڿ��� ������
�ǽ���: 2020 04 20
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/
#include <stdio.h>

void func(int a, int b);
void func_ptr(int *a, int *b);
int cal_sum_arr(int* a, int size);

int main(){
	
	int a = 10 , b = 20 , arr[10], i ; 
	int* ptr_a = &a, * ptr_b = &b;

	func(a, b);
	printf("(call-by-value) a =  %d , b = %d \n", a, b);

	func_ptr(ptr_a, ptr_b);
	printf("(call-by-reference) a = %d , b = %d \n", a, b);

	for (i = 0; i < 10; i++) 
		arr[i] = i + 1;
	printf("sum array element result = %d \n", cal_sum_arr(arr , 10));

	return 0;
}


void func(int a, int b) {
	a += 10;
	b += 10;
}

void func_ptr(int* a, int* b) {
	*a += 10;
	*b += 10;
}

int cal_sum_arr(int* a, int size) {
	int i, sum = 0;
	for (i = 0; i < size; i++)
		sum += *(a + i);
	return sum;
}

