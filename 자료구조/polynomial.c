#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101

typedef struct
{
	float coef;
	int expon;
} polynomial;

polynomial terms[MAX_TERMS] = { {4,3},{2,1},{1,0},{7,2},{6,1},{4,0} };
int avail = 6;
// 두 개의 정수를 비교
char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}
// 새로운 항을 다항식에 추가한다
void attach(float coef, int expon)
{
	if (avail > MAX_TERMS)
	{
		fprintf(stderr, "항의 개수가 너무 많음");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}
//C = A + B
void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce)
{
	float tempcoef;
	*Cs = avail;
	while (As <= Ae && Bs <= Be)
	{
		switch (compare(terms[As].expon, terms[Bs].expon))
		{
		case '>': //A의 차수 > B의 차수
			attach(terms[As].coef, terms[As].expon);
			As++; break;
		case '=': //A의 차수 == B의 차수
			tempcoef = terms[As].coef + terms[Bs].coef;
			if (tempcoef)
				attach(tempcoef, terms[As].expon);
			As++; Bs++; break;
		case '<': //A의 차수 < B의 차수
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++; break;
		}
	}
	//A의 나머지 항들을 이동함
	for (; As <= Ae; As++)
	{
		attach(terms[As].coef, terms[As].expon);
	}
	//B의 나머지 항들을 이동함
	for (; Bs <= Be; Bs++)
	{
		attach(terms[Bs].coef, terms[Bs].expon);
	}
	*Ce = avail - 1;
}
void print_poly(int s, int e)
{
	for (int i = s; i < e; i++)
	{
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	}
	printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

int main(void)
{
	int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce; // As: 첫번째 다항식 시작,  Ae: 첫번째 다항식의 끝,  
                                                // Bs:  두번째 다항식 시작, Be: 두번째 다항식 끝,  
                                                // Cs: 결과 값 다항식을 가리키는 포인터의 시작, Ce: 결과 값 다항식을 가리키는 포인터의 끝 
	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("----------------------------------------\n");
	print_poly(Cs, Ce);
	return 0;
}
