#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int filedes;
void final(void);

int main()
{
	ssize_t nread;
	char buffer[1024];

	atexit(final);

	filedes = open("a.txt", O_RDONLY);
	while((nread = read(filedes, buffer, 1024)) > 0)
	{
		printf("%s", buffer);
	}

	//exit(1);
}


void final(void)
{
	printf("close filedes\n");
	close(filedes);
}
