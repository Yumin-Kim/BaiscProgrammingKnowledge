#include <stdio.h>

/*

�� : ��ǻ�ʹ� 2�� ������ ü�踦 ���!!
2�� ������ ���ϱ� ���ؼ��� 1�� ������ ������ 1�� ���Ѵ�!!

int a  =  3;
l-value  r-value
����     ���
l�ǹ̴� location(��ġ������ �ǹ��Ѵ� >> ������ �ڸ��̸� ������ �޸� �ּҰ��� ������ �̸����� �ǹ̴� �����Ѵ�!!) , left�ǹ̸� ���ϰ� �ִ�
r�ǹ̴� right�ǹ��Ѵ�


type promotion (���°�)
���� �ڷ� ���� ���
'A' + 1 >> int ������ ��ȯ�Ѵ�!!
�ڷ����� ǥ���ϴ� ������ ū������ ���� ����!!
�׷��� int�� �ȴ�!!

�̿Ͱ��� type promotion���� int���� ���� ��ȯ�ϴ� ��찡 ���Ƽ�
putchar(int���� ������� �Ѵ�)

��Ʈ���� �������?
��Ʈ����ũ�� �ϱ� ���ؼ� ���!!
8bits����(���� ����ġ�� ���� ��� ����ġ�ϳ��� 1bit��� �ϸ�)���� ����ġ�� �۵���ų�� �ַ� ����Ѵ�!
��Ʈ����ũ�� ��ǻ���� ����� �������� Ȱ���Ͽ� ������ ������ ���·� ǥ���Ͽ� ��Ʈ������ Ȱ���ϴ� ����Դϴ�.
���÷δ� ip�ּҿ��� network ID���� �˾Ƴ��� ���!!
ip�ּҴ� network ID , Host�� �����Ǿ� �ִµ�


*/


int* convertSecond(int second) {
	int elementsArray[6] = { 0 };
	if (second % 60 != 0) {
		elementsArray[0] = second % 60%10;
		if (second % 60 > 10) {
			elementsArray[1] = second % 60 / 10;
		}
	}
	if (second / 60 != 0) {
		if (second / 60 > 59) {
			elementsArray[4] = second / 3600 % 10;
			if (second / 3600 % 10 > 9) {
				elementsArray[5] = second / 3600 / 10;
			}
		}
		if (second / 60 % 60 != 0) {
			elementsArray[2] = second / 60 % 60 % 10;
			if (second / 60 % 60 > 9) {
				elementsArray[3] = second / 60 % 60 / 10;
			}
		}
	}
	return elementsArray;
}

int main(void) {
	int nData;
	nData = 3; // copy & Overwrite�� �ǹ��Ѵ�

	const int nData_1 = 10; //�� ����ȭ!!
	//nData_1 = 100;lvalue�� ���ȭ�� ��ü�� ���ԵǾ����ϴ�!!

	/*
	������ �ϱ� ���ؼ� �ʱ�ȭ�� ���� ���־���Ѵ�!!
	�ʱ�ȭ ���� �ʰ� ���� �ϰ� �ȴٸ� �����ڰ� �����ϴ� ���ϴ� ���� ������ �ʴ´�!!
	int nTotal;
	nTotal += 1;
	nTotal += 2;
	nTotal += 3;
	*/

	putchar('A'+1);
	printf("\n");
	printf("%d\n", 3 );
	printf("%d\n", ~3 + 1 );
	//~�� ���� 1������ �����Ŀ� 1�� ���ϰԵǸ� -3�� �ȴ�!!

	int input_one = 0;
	int input_two = 0;
	//scanf_s("%d%d", &input_one, &input_two);

	//printf("%0.2f\n", (float)(input_one+input_two)/2);

	int second = 0;
	printf("���ϴ� �ʸ� �Է����ּ��� : ");
	scanf_s("%d", &second);
	int* convertValue = convertSecond(second);

	printf("%d�ʴ� %d%d�ð� %d%d�� %d%d���Դϴ�!!\n",second,convertValue[5], convertValue[4],convertValue[3],convertValue[2],convertValue[1],convertValue[0]);

	printf("Hello Ch04");
	return 0;
}