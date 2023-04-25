#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int filedes;
	mode_t oldmask;

	oldmask = umask(023);
	filedes = open("test.txt", O_CREAT, 0777);
	close(filedes);
}
