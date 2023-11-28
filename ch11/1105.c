#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int fd_read, fd_write, p[2];
	pid_t pid;

	char *buffer;
	char *file1 = "a.txt";
	char *file2 = "b.txt";

	int pipe_size, nread;

	pipe_size = pathconf(file1, _PC_PIPE_BUF);
	printf("pipe size is %d\n", pipe_size);

	pipe(p);
	pid = fork();

	if(pid > 0)     // parent
	{
		printf("file1: hello! (%d)\n", getpid());
		fd_read = open(file1, O_RDONLY);
		buffer = (char *)(malloc(sizeof(char) * pipe_size));
		while((nread = read(fd_read, buffer, pipe_size)) > 0)
			write(p[1], buffer, nread);
		close(fd_read);
		free(buffer);
	}
	else if(pid == 0)       // child
	{
		printf("file2: hello! (%d)\n", getpid());
		fd_write = open(file2, O_RDWR | O_CREAT, 0644);
		buffer = (char *)(malloc(sizeof(char) * pipe_size));
		while((nread = read(p[0], buffer, pipe_size)) > 0)
			write(fd_write, buffer, nread);
		close(fd_write);
		free(buffer);
	}
}
