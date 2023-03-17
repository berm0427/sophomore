#include <stdio.h>
#include <string.h>

int main()
{
	char lyrics[] = "I am just a poor boy ~\n";
	char* p = lyrics;
	int i;

	for (i = 0; i < strlen(lyrics); ++i)
	{
		putchar(lyrics[i]);
	}
	for (i = 0; i < strlen(p); ++i)
	{
		putchar(*(p + i));
	}

	return 0;
}
