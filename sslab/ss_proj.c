#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char b_stack[10];
int top=-1;
int main()
{
	int i,j,k,n,flag=1;
	char inp[100],ch,right,left;
	printf("Enter an arithmatic exp : ");
	scanf("%s",inp);
	for(i=0;i<strlen(inp);i++)
	{
		ch=inp[i];
		if(isalnum(ch))
			printf("%c is an identifier\n",ch);
		else if (ch=='(')
			b_stack[++top]=ch;
		else if (ch==')')
			top--;
		else
		{
			printf("%c is an operator\n",ch);
			right=inp[i+1];
			left=inp[i-1];
			if(!isalnum(left) || !isalnum(right))
				flag=0;
		}
	}
	if(flag==1 && top==-1)
		printf("The expression is valid\n");
	else
		printf("The expression is invalid\n");
	return 0;
}