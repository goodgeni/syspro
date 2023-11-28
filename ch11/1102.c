#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

#define MSGSIZE 11
#define NC      3

int onerror(char *msg)
{
	printf("%s", msg);
	exit(1);
}

int main()
{
	pid_t pid[NC];
	int n, r, c;

	int filedes[NC][2];
	char msg[MSGSIZE];

	fd_set initset, newset;

	for(n = 0; n < NC; n++)
		if(pipe(filedes[n]) == -1)
			onerror("fail to call pipe()\n");

	for(n = 0; n < NC; n++)
	{
		pid[n] = fork();
		if(pid[n] == 0)
			break;
	}

	if(n == NC)     // parent process
	{
		printf("parent: %d\n", getpid());

		for(r = 0; r < NC; r++)
			close(filedes[r][1]);

		FD_ZERO(&initset);
		FD_SET(filedes[0][0], &initset);
		FD_SET(filedes[1][0], &initset);
		FD_SET(filedes[2][0], &initset);

		newset = initset;

		while(select(filedes[2][0] + 1, &newset, NULL, NULL, NULL) > 0)
		{
			if(FD_ISSET(filedes[0][0], &newset))
				if(read(filedes[0][0], msg, MSGSIZE) > 0)
					printf("[parent] %s from child1\n", msg)

						;
			if(FD_ISSET(filedes[1][0], &newset))
				if(read(filedes[1][0], msg, MSGSIZE) > 0)
					printf("[parent] %s from child2\n", msg)

						;
			if(FD_ISSET(filedes[2][0], &newset))
				if(read(filedes[2][0], msg, MSGSIZE) > 0)
					printf("[parent] %s from child3\n", msg)

						;
			newset = initset;
		}

	}
	
	else if (n == 0)
	{
		printf("child1 : %d\n", getpid());

		for(r = 0; r < NC; r++)
			close(filedes[r][0]);
		close(filedes[1][1]);
		close(filedes[2][1]);

		for(r = 0; r < 3; r++)
		{
			sleep((r + 1) % 4);
			printf("child1 : send message %d\n", r);
			write(filedes[0][1], "i'm child1", MSGSIZE);
		}

		printf("child1 : bye!\n");
		exit(0);
	}
	else if(n == 1) //2nd child
	{
		printf("child2 : %d\n", getpid());

		for(r = 0; r < NC; r++)
			close(filedes[r][0]);
		close(filedes[0][1]);
		close(filedes[2][1]);

		for(r = 0; r < 3; r++)
		{
			sleep((r + 3) % 4);
			printf("chlid2 : send message %d\n", r);
			write(filedes[1][1], "i'm child2", MSGSIZE);
		}

		printf("child2 : bye!\n");
		exit(0);
	}
	else if(n == 2)
	{
		printf("child3 : %d\n", getpid());

		for(r = 0; r < NC; r++)
			close(filedes[r][0]);
		close(filedes[0][1]);
		close(filedes[1][1]);

		for(r = 0; r < 3; r++)
		{
			sleep((r + 5) % 4);
			printf("child3 : send message %d\n", r);
			write(filedes[2][1], "i'm child3", MSGSIZE);
		}

		printf("child3 : bye!\n");
		exit(0);
	}
}
