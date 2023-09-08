#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int filedes;

	if((filedes = open(argv[1], O_RDWR | O_CREAT | O_EXCL, 0644)) == -1)
	{
		printf("file open error!\n");
		exit(1);
	}

	close(filedes);
}
