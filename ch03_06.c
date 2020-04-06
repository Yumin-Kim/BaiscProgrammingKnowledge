/*
실습명:교제 2-7 다항식 , x값 대입시 다항식의 결과 값
교수님 성함: 박웅규 교수님
실습일: 2020 04 01
학과 : 멀티 미디어 학과
학번 : 201610309
이름 : 김유민
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

	printf("다항식의 최고 차수를 입력하시오\n");
	scanf("%d",&p.degree);
	printf("각 항의 계수를 입력하시오 (총 : %d 개) : ",p.degree+1);
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
	printf("다항식에 대입할 숫자를 입력하시요\n");
	scanf("%f", &num);
	printf("%4.1f\n", cal_Poly(c, num) );
	return 0;
}

