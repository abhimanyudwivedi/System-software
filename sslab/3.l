%{
	#include<stdio.h>
	int count=0;
	char ch;
%}
%%
.|\n {;}
"int"|"float"|"double"|"char" {ch = input();
								if(ch==',')
									count++;
								else if(ch=';')
								{
									count++;
									break;
								}
								ch = input();
							  }
%%
int main(int argc,char *argv[])
{
	if(argc==2)
	{
		yyin = fopen(argv[1],"r");
		yylex();
		printf("\nthe number of identifiers in the file are %d",count);
	}
	return 0;
}
