#include <stdio.h>

int main() {
	//*����� �����Ͷ�°� ��ǻ���ѵ� �˷��ִ°��̰� ��½� ������ ������ ���� ���� �˼� �ִ� &�� ������ ������ �ִ� RAM�� �ּ�
	//�����ʹ� ������ �ּҸ� �˰� �־ ������ ������ ���� ���Ҵ� ���ָ� ���� ���踦 ������ ���� �����ͺ����� �����ߴ� ������ ���� ���Ѵ�
	int a = 10;
	char b = "1";
	int* ptr_a;
	ptr_a = &a;

	printf("%d variable ptr_a RAM address \n", ptr_a);
	printf("%d variable ptr_a  \n", *ptr_a);
	printf("%d variable A RAM address \n", &a);
	printf("%d variable A sizeof \n", sizeof(a));
	printf("%d variable B char RAM address \n", &b);

	printf("a result : %d \n", a);
	//���� ��ü�� �ҷ� �;� �ϱ� ������ *ptr_a �Ҵ��ؾ��Ѵ�
	//������ �ּҸ� �Ҵ��Ҷ��� *���� 
	//������ ���� �Ҵ��Ҷ��� *�ʿ�
	*ptr_a = 100;
	printf("a result : %d \n ", a);

	*ptr_a = &a;
	printf("a result : %d \n ", a);
	printf("���� ������!!\n");
	//����������
	int c = 10;
	int *ptr_c = &c;
	int** ptr_ptr_c = &ptr_c;

	printf(" c result : %d\n ", c);
	printf(" c address : %d\n ", &c);
	printf(" ptr result : %d \n", *ptr_c);
	printf(" ptr address : %d \n", ptr_c);
	printf(" **ptr result : %d \n", *ptr_ptr_c);
	printf(" **ptr address : %d \n", ptr_ptr_c);
	printf(" **ptr result in   : %d \n", *(*ptr_ptr_c));

	//�迭�� ������
	printf("�迭 ������!!\n");

	int i = 0,arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*ptr_arr)[10] = &arr;
	printf("arr  %d\n", arr);
	printf("arr+1  %d\n", arr+1);
	printf("&arr  %d\n", &arr);
	printf("&arr +1  %d\n", &arr+1);
	printf("ptr_arr  %d\n", ptr_arr);
	printf("ptr_arr+1  %d\n", ptr_arr+1);
	printf("&ptr_arr  %d\n", &ptr_arr);
	printf("*ptr_arr  %d\n", *(*ptr_arr)+10 );
	printf("*ptr_arr+1  %d\n", *(*ptr_arr +1));
	printf("&arr+1  %d\n", &arr+1);
	while ( i < sizeof(arr) / sizeof(int)) {
		printf("%d��° �迭 �� %d \n", i, arr[i]);
		printf("%d��° �迭 �� *(arr+i) : %d \n", i, *(arr+i));
		printf("%d��° �迭 address &arr : %d \n", i, &arr[i]);
		printf("%d��° �迭 address arr : %d \n", i, arr+i);
		i++;
	}
	
	for (int* ptr = arr; ptr < arr + 10; ptr++) {
		printf("*ptr address arr : %d \n",*ptr);
	}
	//�迭 ������ >> arr[i] == *(arr + i) == *(ptr+i) == *(i + ptr) >> i[ptr]
	

	return 0;
}