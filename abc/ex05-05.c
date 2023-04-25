#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 256

void printcwd()
{
	char buffer[BUF_SIZE];

	if(getcwd(buffer, BUF_SIZE) == NULL)
		exit(1);

	printf("%s\n", buffer);
}

int main()
{
	printcwd();
	chdir("/usr/include");
	printcwd();
	chdir("..");
	printcwd();
}
