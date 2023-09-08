#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int filedes;
	char pathname[] = "temp.txt";

	if((filedes = open(pathname, O_RDWR | O_CREAT | O_EXCL, 0644)) == -1)
	{
		printf("file open error!\n");
		exit(1);
	}

	close(filedes);
}
