#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i,j,n,m;
int all[10][10],max[10][10],avail[10],need[10][10],work[10],req[10];
struct process
{
	char name[5];
	int flag;
}p[10];
void input()
{
	printf("\nenter the number of processes");
	scanf("%d",&n);
	printf("enter the process name");
	for(i=0;i<n;i++)
	{
		scanf("%s",p[i].name);
	}
	printf("\nenter the number of resources");
	scanf("%d",&m);
	printf("enter the allocated matrix");
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	scanf("%d",&all[i][j]);
	printf("enter the max matrix");
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	scanf("%d",&max[i][j]);
	printf("the need matrix");
	for(i=0;i<n;i++)
	{for(j=0;j<m;j++)
	{need[i][j]=max[i][j]-all[i][j];
	 printf("%d",need[i][j]);
	}
	 printf("\n");
	}
	printf("enter the avail matrix");
	for(j=0;j<m;j++)
	scanf("%d",&avail[j]);
}
void safeseq()
{
	int chk=0,chki=0,sseq[10],ss=0,count=0;
	for(i=0;i<m;i++)
	work[i]=avail[i];
	for(i=0;i<n;i++)
	p[i].flag=0;
	while(count!=n)
	{	
		for(i=0;i<n;i++)
		{
			chk=0;
			for(j=0;j<m;j++)
			{
				if(p[i].flag==0)
				{
					if(need[i][j]<=work[j])
					chk++;
				}
				if(chk==m)
				{
					for(j=0;j<m;j++)
					{	work[j]=work[j]+all[i][j];
						printf("%d\t",work[j]);
						p[i].flag=1;
					}	
				 printf("\n");
				sseq[ss]=i;
				ss++;
				count++;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	if(p[i].flag==1)
	chki++;
	if(chki==n)
	{
		printf("safe sequence is:\n");
		for(j=0;j<n;j++)
		printf("%d",sseq[j]);
	}
	else
	{
	printf("not safe");
	}	
}
void request()
{
	int pro;
	printf("\nenter the process number");
	scanf("%d",&pro);
	printf("enter the request matrix");
	for(j=0;j<m;j++)
	scanf("%d",&req[j]);
	for(j=0;j<m;j++)
	{
		if(need[pro][j]>=req[j])
			{
				if(req[j]<=avail[j])
				{
					avail[j]=avail[j]-req[j];
					need[pro][j]=need[pro][j]-req[j];
					all[pro][j]=all[pro][j]+req[j];
					printf("avail:%d",avail[j]);
				}
				printf("need:%d",need[i][j]);
			}
		else
			{
				printf("process has some error");
				exit(0);
			}	
	}
}
void output()
{
	printf("max matrix\n");
	for(i=0;i<n;i++)
	{for(j=0;j<m;j++)
	printf("%d",max[i][j]);
	printf("\n");
	}
	printf("the need matrix\n");
	for(i=0;i<n;i++)
	{for(j=0;j<m;j++)
	printf("%d\t",need[i][j]);
	printf("\n");
	}
	printf("allocated matrix");
	for(i=0;i<n;i++)
	{for(j=0;j<m;j++)
	printf("%d\t",all[i][j]);
	printf("\n");
	}
}
int main()
{	int ch;
	do{
	printf("menu\n");
	printf("\n1.input\n2.safeseq\n3.request\n4.output\n999. to exit\n");
	printf("enter a choice");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1: input();
			break;
	case 2: safeseq();
			break;
	case 3: request();
			break;
	case 4: output();
			break;
	default:break;
	}
	}while(ch!=999);
	return 0;								
}
