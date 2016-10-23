#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
char buf1[] = "abcdefghijklmnop";
char buf2[] = "ABCDEFGHIJKLMNOP";
int main()
{
	int fd;
	fd=creat("file.txt",S_IRWXU);
	if(fd<0)
	{
		printf("error while creating file");
		exit(0);
	}
	write(fd,buf1,16);
	lseek(fd,48,SEEK_SET);
	write(fd,buf2,16);
	system("gedit file.txt");
	return 0;
}
