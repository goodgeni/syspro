#include <stdio.h>

int main()
{
	FILE *file;

	file = fopen("test.txt", "r");

	printf("%c\n", fgetc(file));

	fclose(file);
}
