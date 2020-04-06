#include <stdio.h>

int main() {
	//*선언시 포인터라는걸 컴퓨터한데 알려주는것이고 출력시 포인터 변수가 가진 값을 알수 있다 &은 변수를 가지고 있는 RAM의 주소
	//포인터는 변수의 주소를 알고 있어서 포인터 변수에 값을 재할당 해주면 참조 관계를 가지고 원래 포인터변수와 선언했던 변수의 값이 변한다
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
	//변수 자체를 불러 와야 하기 때문에 *ptr_a 할당해야한다
	//변수의 주소를 할당할때는 *없이 
	//변수의 값을 할당할때는 *필요
	*ptr_a = 100;
	printf("a result : %d \n ", a);

	*ptr_a = &a;
	printf("a result : %d \n ", a);
	printf("이중 포인터!!\n");
	//이중포인터
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

	//배열과 포인터
	printf("배열 포인터!!\n");

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
		printf("%d번째 배열 값 %d \n", i, arr[i]);
		printf("%d번째 배열 값 *(arr+i) : %d \n", i, *(arr+i));
		printf("%d번째 배열 address &arr : %d \n", i, &arr[i]);
		printf("%d번째 배열 address arr : %d \n", i, arr+i);
		i++;
	}
	
	for (int* ptr = arr; ptr < arr + 10; ptr++) {
		printf("*ptr address arr : %d \n",*ptr);
	}
	//배열 포인터 >> arr[i] == *(arr + i) == *(ptr+i) == *(i + ptr) >> i[ptr]
	

	return 0;
}