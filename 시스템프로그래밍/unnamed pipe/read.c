/*
  read.c
  unnamed pipe�� ���� ����.
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[30];
	fputs("---Output from read.c---\n", stdout);
	while(1)
	{
		fgets(str, sizeof(str), stdin);
		if(!strncmp("stop", str, 4))
			break;
		fputs(str, stdout);
	}

	return 0;
}