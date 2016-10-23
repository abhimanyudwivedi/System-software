#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
	pid_t pid,i,n;
	char cmd[15];
	system("clear");
	printf("\nenter the number of commands");
	scanf("%d",&n);
	pid = fork();
	if(pid<0)
	{
		printf("\nerror while creating a child process");
		exit(0);
	}
	else if(pid==0)
	{
	printf("\nchild process");
	for(i=0;i<n;i++)
	{
		printf("\nenter the command");
		scanf("%s",cmd);
		system(cmd);
	}
	}
	else
	{
		wait();
		printf("\nparent process completed\n");
	}
	return 0;
}      
