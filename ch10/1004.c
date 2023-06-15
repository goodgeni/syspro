#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void handler(int signum);

int main()
{
	pid_t pid;

	struct sigaction act;

	sigfillset(&(act.sa_mask));
	act.sa_handler = handler;
	sigaction(SIGINT, &act, NULL);

	if((pid = fork()) > 0)
	{
		printf("[parent] hello\n");
		pause();
		printf("[parent] bye!\n");
	}
	else if(pid == 0)
	{
		printf("[child] hello\n");
		sleep(1);
		kill(getppid(), SIGINT);
		printf("[child] bye\n");
	}
	else
		printf("fail to fork\n");
}

void handler(int signum){
	printf("a\n");	
}
