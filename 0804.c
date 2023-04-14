#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	time_t result;
	pid_t pid;

	int filedes;
	char buffer[32];

	pid = fork();

	if(pid > 0)
	{
		sleep(1);
		exit(1);
	}
	else if(pid == 0)
	{
		setsid();
		filedes = open("./curtime.txt", O_RDWR | O_CREAT, 0644);
		for(;;)
		{
			result = time(NULL);
			strcpy(buffer, asctime(localtime(&result)));
			printf("%s", buffer);
			write(filedes, buffer, strlen(buffer));
			sleep(10);
		}
	}

}
