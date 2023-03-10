#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int factorial(int n)
{
	if (n <= 1) return (1);
	else return (n * factorial(n - 1));
}

int main()
{
	int argc;
	printf("[>] 원하는 숫자를 입력 \n[<] ");
	scanf("%d", &argc);

	printf("%d\n",factorial(argc));

	return 0;
}

