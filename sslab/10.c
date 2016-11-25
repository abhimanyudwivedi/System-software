#include <stdio.h>
#include <stdlib.h>
struct proc
{
	int id, arrival, burst, rem, wait, finish, turnaround;
	float ratio;
}process[10];
struct proc temp;

int no;
void roundrobin(int n,int tq,int st[],int bt[])
{
	//wt : Wait Time
	//tat : Turn Around Time
	//bt : Burst Time
	//st : Shortest Time
	int time,tat[10],wt[10],i,count=0,swt=0,stat=0,temp,sq=0,j,k;
	float awt=0.0,atat=0.0;
	while(1)
	{
		for(i=0,count=0;i<n;i++)
		{
			temp=tq;
			if(st[i]==0)
			{
				count++;
				continue;
			}
			if(st[i]>tq)
					st[i]=st[i]-tq;
			else if(st[i]>=0)
			{
				temp=st[i];
				st[i]=0;
			}
			sq=sq+temp;
			tat[i]=sq;
		}
		if(n==count)
				break;
	}
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
		swt=swt+wt[i];
		stat=stat+tat[i];
	}
	awt=(float)swt/n;
	atat=(float)stat/n;
	printf("Process no\tBurst Time\tWait Time\tTurn Around Time\n");
	for(i=0;i<n;i++)
		printf("%d\t\t%d\t\t%d\t\t%d\t\t\n",i+1,bt[i],wt[i],tat[i]);
	printf("Avg wait time : %f\nAvg Turn Around Time : %f\n",awt,atat);
}

int chkprocess(int s)
{
	int i;
	for(i=0;i<s;i++)
		if(process[i].rem!=0)
			return 1;
	return 0;
}

int nextprocess()
{
	int min,i,pnum;
	min=32000;
	for(i=0;i<no;i++)
		if(process[i].rem!=0 && process[i].rem<min)
		{
			min=process[i].rem;
			pnum=i;
		}
	return pnum;
}

void srtf(int n)
{
	int i,j,k,time=0;
	float tavg=0.0,wavg=0.0;
	for(i=0;i<n;i++)
	{
		process[i].id=i+1;
		printf("Enter arrival time of process %d : ",i+1);
		scanf("%d",&(process[i].arrival));
		printf("Enter burst time of process %d : ",i+1);
		scanf("%d",&(process[i].burst));
		process[i].rem=process[i].burst;
	}
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(process[i].arrival>process[j].arrival)
			{
				temp=process[i];
				process[i]=process[j];
				process[j]=temp;
			}
	no=0;
	j=0;
	while(chkprocess(n)==1)
	{
		if(process[no].arrival==time)
		{
			no++;
			if(process[j].rem==0)
					process[j].finish=time;
			j=nextprocess();
		}
		if(process[j].rem!=0)
			process[j].rem--;
		else
		{
			process[j].finish=time;
			j=nextprocess();
			time--;
		}
		time++;
	}
	process[j].finish=time;
	printf("Shortest Remaining Time First\n");
	printf("Process\tarrival\tBurst\tWaiting\tFinish\tTurnaround\tTR\n");
	for(i=0;i<n;i++)
	{
		process[i].turnaround=process[i].finish-process[i].arrival;
		process[i].wait=process[i].turnaround-process[i].burst;
		process[i].ratio=(float)process[i].turnaround/process[i].burst;
		printf("%5d%8d%7d%8d%10d%9d%10.1f",process[i].id,process[i].arrival,process[i].burst,process[i].wait,process[i].finish,process[i].turnaround,process[i].ratio );
		tavg=tavg+process[i].turnaround;
		wavg=wavg+process[i].wait;
		printf("\n\n");
	}
	tavg=tavg/n;
	wavg=wavg/n;
	printf("Tavg : %f\nWavg : %f\n",tavg,wavg);
}

int main()
{
	int n,tq,choice,bt[10],st[10],i,j,k;
	while(1)
	{
		printf("\n\n1.Round Robin Scheduling Algorithm\n2.Shortest Remaining Time Next\n3.Exit\n");
		printf("Enter choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("ROUND ROBIN SCHEDULING ALGORITHM\n");
				printf("Enter number of processes :");
				scanf("%d",&n);
				printf("Enter burst time for sequences \n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&bt[i]);
					st[i] = bt[i];
				}
				printf("Enter time quantum : ");
				scanf("%d",&tq);
				roundrobin(n,tq,st,bt);
				break;
			case 2:
				printf("SHORTEST REMAINING TIME NEXT\n");
				printf("Enter number of processes : ");
				scanf("%d",&n);
				srtf(n);
				break;
			case 3:
				exit(0);
			default:
				printf("Invalid choice\n");
				continue;
		}
	}
	
}

/*
OUTPUT :
[jayasurya@jayasurya-pc SS]$ gcc 10.c 
[jayasurya@jayasurya-pc SS]$ ./a.out 

1.Round Robin Scheduling Algorithm
2.Shortest Remaining Time Next
3.Exit
Enter choice : 1
ROUND ROBIN SCHEDULING ALGORITHM
Enter number of processes :3
Enter burst time for sequences 
24
3
3
Enter time quantum : 4
Process no	Burst Time	Wait Time	Turn Around Time
1			24			6			30		
2			3			4			7		
3			3			7			10		
Avg wait time : 5.666667
Avg Turn Around Time : 15.666667


1.Round Robin Scheduling Algorithm
2.Shortest Remaining Time Next
3.Exit
Enter choice : 2
SHORTEST REMAINING TIME NEXT
Enter number of processes : 4
Enter arrival time of process 1 : 0
Enter burst time of process 1 : 8
Enter arrival time of process 2 : 1
Enter burst time of process 2 : 4
Enter arrival time of process 3 : 2
Enter burst time of process 3 : 9
Enter arrival time of process 4 : 3
Enter burst time of process 4 : 5
Shortest Remaining Time First
Process	arrival	Burst	Waiting	Finish	Turnaround    TR
    1       0      8       9        17       17       2.1

    2       1      4       0         5        4       1.0

    3       2      9      15        26       24       2.7

    4       3      5       2        10        7       1.4

Tavg : 13.000000
Wavg : 6.500000


1.Round Robin Scheduling Algorithm
2.Shortest Remaining Time Next
3.Exit
Enter choice : 3
*/