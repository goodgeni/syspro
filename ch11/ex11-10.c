#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
<<<<<<< HEAD

#define MSGSIZE 16

void parent(int [][]);
int child(int []);

void onerror(char *msg)
{
	printf("%s");
	exit(1);
}

main()
=======
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define MSGSIZE 16

//void parent(int [][]);
//int child(int []);

void onerror(char *msg)
{
	printf("%s", msg);
	exit(1);
}

int main()
>>>>>>> f4951ba (11)
{
	int p1[2], p2[2];
	char msg[MSGSIZE];
	int i;
	pid_t pid1, pid2;
	fd_set initset, newset;

	pid1 = pid2 = 0;

	if(pipe(p1) == -1)
		onerror("fail to call pipe() #1\n");
	if(pipe(p2) == -1)
		onerror("fail to call pipe() #2\n");

	if((pid1 = fork()) == -1)
		onerror("fail to call fork() #1\n");
	if(pid1 > 0)
		if((pid2 = fork()) == -1)
			onerror("fail to call fork() #2\n");

	if(pid1 > 0 && pid2 > 0) {
		printf("parent: %d\n", getpid());
<<<<<<< HEAD
		close(p1[1]); close(p1[1]);
=======
		close(p1[1]); close(p2[1]);
>>>>>>> f4951ba (11)

		FD_ZERO(&initset);
		FD_SET(p1[0], &initset);
		FD_SET(p2[0], &initset);

		newset = initset;
		while(select(p2[0] + 1, &newset, NULL, NULL, NULL) > 0) {
			if(FD_ISSET(p1[0], &newset))
				if(read(p1[0], msg, MSGSIZE) > 0)
					printf("[parent] %s from child1\n", msg);
			if(FD_ISSET(p2[0], &newset))
				if(read(p2[0], msg, MSGSIZE) > 0)
					printf("[parent] %s from child2\n", msg);
			newset = initset;
		}
	}
	else if(pid1 == 0 && pid2 == 0) {
		printf("child1: %d\n", getpid());
		close(p1[0]); close(p2[0]); close(p2[1]);

<<<<<<< HEAD
		for(i = 0; i < 3; i++) {
			sleep((i + 1) % 4);
			printf("child1: send message %d\n", i);
			write(p1[1], "i'm child1", MSGSIZE);
=======
//		char buf1[] = "i'm child1";
		for(i = 0; i < 3; i++) {
			sleep((i + 1) % 4);
			printf("child1: send message %d\n", i);
//			write(p1[1], buf1, sizeof(buf1));
			write(p1[1], "i'm child1", 11);

>>>>>>> f4951ba (11)
		}
		printf("child1: bye!\n");
		exit(0);
	}
	else if(pid1 > 0 && pid2 == 0) {
		printf("child2: %d\n", getpid());
		close(p1[0]); close(p1[1]); close(p2[0]);

		for(i = 0; i < 3; i++) {
			sleep((i + 3) % 4);
			printf("child2: send message %d\n", i);
<<<<<<< HEAD
			write(p2[1], "i'm child2", MSGSIZE);
=======
			write(p2[1], "i'm child2", 11);
>>>>>>> f4951ba (11)
		}
		printf("child2: bye!\n");
		exit(0);
	}
}
