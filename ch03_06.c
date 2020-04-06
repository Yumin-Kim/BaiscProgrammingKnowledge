/*
�ǽ���:���� 2-7 ���׽� , x�� ���Խ� ���׽��� ��� ��
������ ����: �ڿ��� ������
�ǽ���: 2020 04 01
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/
#include <stdio.h>
#include <string.h>

#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}Polynomial;



void print_poly(Polynomial p, char str[]) {
	int i;
	printf("\t%s",str);
	for (i = 0; i < p.degree; i++) {
		printf("%5.1f x ^%d + ",p.coef[i],p.degree-i);
	}
	printf("%4.1f\n",p.coef[p.degree]);
}
void print_poly2(Polynomial p, char str[]) {
	int i;
	printf("\t%s", str);
	for (i = 0; i < p.degree; i++) {
		if (i == 0) 
			printf("%5.1f x ^%d  ", p.coef[i], p.degree - i);
		else if(p.coef[i] > 0 )
			printf(" + %5.1f x ^%d ", p.coef[i], p.degree - i);
		else 
			printf(" - %5.1f x ^%d ", -p.coef[i], p.degree - i);
	}
		if (p.coef[p.degree] > 0) printf("+ %4.1f\n", p.coef[p.degree]);
		else printf("- %4.1f\n", -p.coef[p.degree]);
}

Polynomial read_poly() {
	int i;
	Polynomial p;

	printf("���׽��� �ְ� ������ �Է��Ͻÿ�\n");
	scanf("%d",&p.degree);
	printf("�� ���� ����� �Է��Ͻÿ� (�� : %d ��) : ",p.degree+1);
	for (i = 0; i <= p.degree; i++) {
		scanf("%f", p.coef + i);
	}
	return p;
}


double cal_Poly(Polynomial p, double x) {
	double tmp1 = 0;
	int i;
	for (i = 0; i < p.degree; i++) {
	double tmp = 1;
		for (int j = 0; j < p.degree-i; j++) {
			tmp *= x;
		}
		tmp *= p.coef[i];
		tmp1 += tmp;
	}
	tmp1 += p.coef[p.degree];
	return tmp1;
}

Polynomial add_poly(Polynomial a , Polynomial b) {
	int i;
	Polynomial p;
	if (a.degree > b.degree) {
		p = a;
		for (i = 0; i <= b.degree; i++) {
			p.coef[i + (p.degree - b.degree)] += b.coef[i];
		}
	}
	else {
		p = b;
		for (i = 0; i <= a.degree; i++) {
			p.coef[i + (p.degree - a.degree)] += a.coef[i];
		}
	}
	return p;
}
int main() {
	Polynomial a, b, c;
	float num;
	a = read_poly();
	b = read_poly();
	c = add_poly(a,b);
	print_poly2(a," A =  ");
	print_poly2(b," B =  ");
	print_poly2(c," A + B =  ");
	printf("���׽Ŀ� ������ ���ڸ� �Է��Ͻÿ�\n");
	scanf("%f", &num);
	printf("%4.1f\n", cal_Poly(c, num) );
	return 0;
}

