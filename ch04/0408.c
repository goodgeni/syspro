#include <unistd.h>
#include <stdio.h>

int main()
{
	if(!access("./b.txt", F_OK))
		printf("Ok!!\n");
	else
		printf("Sorry!!\n");
}
