#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 512

int main()
{
	char msg[SIZE];
	int filedes[2];
	int i;

	if(pipe(filedes)==-1){
		printf("fail to call\n");
		exit(1);
	}

	for(i=0; i<3; i++){
		printf("input a message\n");
		fgets(msg, SIZE, stdin);
		write(filedes[1], msg, SIZE);
	}

	printf("\n");

	for(i=0; i<3; i++){
		read(filedes[0], msg, SIZE);
		printf("%s", msg);
	}


}
