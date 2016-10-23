#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid<0)
	{
		printf("\nerror while creating child process");
		exit(0);
	}
	else if(pid == 0)
	{
		printf("\nchild process");
		printf("\nchild process id: %d",getpid());
		printf("\nparent process id: %d",getppid());
	}
	else
	{	
		wait();
		printf("\nparent process");
		printf("\nparent process id: %d",getpid());
		printf("\nchild process id: %d\n",pid);
	}
	return 0;
}
