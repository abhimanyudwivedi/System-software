%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B
%%
S:A S B|;
%%
int main()
{
	printf("\nenter the string\n");
	yyparse();
	printf("\nthe stringis valid\n");
	return 1;
}
int yyerror()
{
	printf("\nthe string is invalid\n");
	exit(0);
}
