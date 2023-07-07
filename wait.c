#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main()
{
	int   counter  = 1;
	int   status;
	pid_t pid;
	pid_t pid_child;

	pid = fork();

	switch(pid){
		case -1 :
			printf( "자식 프로세스 생성 실패\n");
			return -1;
		case 0 :
			printf( "저는 자식 프로세스로 5까지 카운트하고 종료하겠습니다.\n");
			while( 6 > counter ){
				printf( "자식: %d\n", counter++);
				sleep( 1);
			}
			return 99;
		default  :
			printf("저는 부모 프로세스로 자식 프로세스 작업이 끝날 때 까지 대기합니다.\n");

			pid_child = wait(&status);

			printf("종료된 자식 프로세스 ID는 %d이며,", pid_child);
			
			if (WIFEXITED(status)){
				printf( "정상적으로 종료되었고 반환값은 %d입니다\n", WEXITSTATUS(status));
			}
			else{
				printf( "비 정상으로 종료되었고 종료 시그널 번호는 %d입니다\n", status);
			}	
			printf( "이제 제일을 처리하겠습니다.\n");

			while(1){
				printf( "부모: %d\n", counter++);
				sleep( 1);
			}
	}
}
