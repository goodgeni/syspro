// ./a.out &
// ps au | grep Z+

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	pid_t pid = fork();

	if(pid == 0) // child process
	{
		puts("Hi, I am a child process");
		puts("End child process");
	}

	else
	{
		printf("Child PID : %d \n", pid);
		sleep(30);
		puts("End parent process");
	}

	return 0;
}
