/*
  write.c
  unnamed pipe�� ���� ����.
*/

#include <stdio.h>

int main(void)
{
	fputs("AAA \n", stdout);
	fputs("BBB \n", stdout);
	fputs("CCC \n", stdout);
	fputs("stop \n", stdout); 

	return 0;
}