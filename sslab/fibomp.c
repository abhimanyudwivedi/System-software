#include<stdio.h>
#include<omp.h>
int main()
{
	int i,n,fib[100];
	printf("\nenter the range(<100)");
	scanf("%d",&n);
	fib[0]=0;
	fib[1]=1;
	if(n<=2)
	{
		printf("\n%d\n%d\n",fib[0],fib[1]);
	}
	else
	{
		printf("\nthread 1 generating fibonacci series");
		#pragma omp parallel num_threads(2)
		for(i=2;i<n;i++)
		{
			fib[i]=fib[i-1]+fib[i-2];
		}
	}
	printf("\nthread 2 printing the fibonacci series\n");
	#pragma omp critical
	for(i=0;i<n;i++)
	{
		printf("%d\n",fib[i]);
	}
	return 0;
}
