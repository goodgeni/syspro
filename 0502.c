#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>

int isDir(char *);

int main(int argc, char *argv[])
{
	DIR *dirp;
	struct dirent *dentry;
	int num_dir = 0, num_fil = 0;

	if(argc != 2)
		return 0;

	if((dirp = opendir(argv[1])) == NULL)
		return 0;

	while(dentry = readdir(dirp))
	{
		if(dentry->d_ino != 0)
		{
			if(isDir(dentry->d_name) == 0)
				num_dir++;
			else
				num_fil++;
		}
	}

	printf("%d dirs, %d files\n", num_dir, num_fil);

	closedir(dirp);
}

int isDir(char *name)
{
	DIR *dirp;
	dirp = opendir(name);
	closedir(dirp);
	return dirp == NULL ? 1 : 0;
}
