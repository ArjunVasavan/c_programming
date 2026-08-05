#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct stat statbuf;
	int fd1 = open("test1.txt", O_RDONLY);
	if (fd1 == -1)
	{
		perror("open fd :\n");
		return 0;
	}
	char buff[10];
	printf("fd = %d\n", fd1);
	if (read(fd1, buff, 10) == -1)
	{
		perror("read :\n");
		return 0;
	}
	fstat(fd1, &statbuf);

	int fd2 = open("test2.txt", O_WRONLY | O_CREAT, 0666);
	if (fd2 == -1)
	{
		perror("open test2 :\n");
		return 0;
	}
	if (write(fd2, buff, 10) == -1)
	{
		perror("write :\n");
		return 0;
	}
	fchmod(fd2, statbuf.st_mode);
	printf("fd = %d\n", fd2);
}
