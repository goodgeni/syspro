#include <stdio.h>


int sum(){

	int i, sum=0;

	for(i=1; i<=100; i++)
	{
		sum += i;
	}

	printf("sum of 1~100 : %d\n", sum);

	return 0;
}
