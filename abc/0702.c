#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int gNum;

int main()
{
	pid_t fpid;
	fpid = fork();
	
	 if(fpid > 0)
	 {
         while(1)
        {
		 printf("Parent_forkpid(%4d) : getpid(%4d), getppid(%4d), gNum(%d)\n", 
				 (int)fpid, (int)getpid(), (int)getppid(), gNum);
			sleep(5);
			gNum++;
		}
	}
	else if(fpid==0)
	{
		while(1)
        {   
			pid_t gpid  = getpid();
			pid_t gppid = getppid();
			printf("child_forkpid(%4d) : getpid(%4d), getppid(%4d), gNum(%d)\n", 
					  (int)fpid, (int)getpid(), (int)getppid(), gNum);
			sleep(5);
			gNum++;
	}
	}
} 

