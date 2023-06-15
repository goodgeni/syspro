#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>

int isDir(char *);

int main(int argc, char *argv[])
{
	if(argc != 2)
		return 0;

	if(isDir(argv[1]))
		printf("%s not exist\n", argv[1]);
	else
		printf("%s exist\n", argv[1]);
}

int isDir(char *path)
{
	DIR *dirp;
	dirp = opendir(path);
	closedir(dirp);
	return dirp == NULL ? 1 : 0;
}
