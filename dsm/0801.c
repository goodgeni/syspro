#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
	int x, y, i;
	pid_t pid;
	int c_result = 0, p_result = 1;

	printf("input two numbers (1~10) : ");
	scanf("%d %d", &x, &y);

	pid = fork();

	if(pid > 0)
	{
		for(i = 0; i < y; i++){
			p_result *= x;
		}

		printf("parent : %d\n", p_result);
		wait(&c_result);
		c_result = c_result >> 8;
		printf("result is %d\n", p_result + c_result);
	}

	else if(pid == 0)
	{
		for(i = x; i <= y; i++)
			c_result += i;
		printf("child : %d\n", c_result);
		exit(c_result);
	}
}
