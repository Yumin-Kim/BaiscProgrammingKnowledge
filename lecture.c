# include <stdio.h> //��ó���� stdio.h ���̺귯�� �����ϰڴ�
//���� ram�� �Ҵ��Ѵ�
//visual stdio������ ��ü������ ��� ������ build �ϱ� ������ ���� ��Ŭ���Ŀ� �Ӽ����� ���� ���ܸ� �����ϸ� main �Լ��� �ߺ��ǰ� ������ ���� �� �� �ִ�
//int 32bit >> 4byte >>���� 00000000 00000000 00000000 00000101 >> int a = 5;
//8bit = 1byte >> ��ǻ�Ϳ��� �����͸� ó���ϴ� ���� ���� ����

int main() //C���α׷��� ��ü ������ �����ϴ� ����
{
	int num1 = 241;
	int num2 = 32;
	printf("%c \n ", 'a');
	printf("%c \n ", 'aasd');
	printf("%s \n", "hello world");
	printf("%g \n", 3.1234123124124);
	printf("%.3g\n ", 3.1234123124124);

	int a; char b; float c; double d; char str[100] ="Hello world";
	//sizeof �ڷ����� ũ�⸦ �˷��ش� byte�� ǥ��
	printf("%d %d %d %d %d \n", sizeof(a), sizeof(b), sizeof(c), sizeof(d) , sizeof(str));

	//����ȯ (�ڷ����� ���� �ش�)sum >> �ڷ����� ū�ɷ�(������ ū�ɷ� ����ȯ ) ����ȯ�� ���ش�
	int sum = num1 + num2 + 7;
	double division = (double)sum / 3;
	printf("%f \n", division);

	printf("%c\n", 97);//ASCode�� ���� == ���� >> 97 >> a��ȯ 

	char str1;
	scanf("%c", &str1);

	printf("%c %d", str1, str1);

	/*
	//�Է� �ޱ� >> _CRT_SECURE_NO_WARNINGS �Ӽ��� ��ó���� ���� �ȿ� �߰��ؾ��� scanf_s �Ⱦ��� �۵��Ѵ�
	//scanf ���� �ٸ� ���ڿ��� ���� ���� ����
	int scanf_num1, scanf_num2;
	printf("���� �Է�");
	scanf("%d %d", &scanf_num1, &scanf_num2);

	printf("��� : %d %d\n", scanf_num1, scanf_num2);

	float scanf_flo1, scanf_flo2;
	printf("�Ǽ� �Է�");
	scanf("%f %f", &scanf_flo1, &scanf_flo2);

	printf(" %f ,%f \n ", scanf_flo1, scanf_flo2);
	*/
	return 0;
}