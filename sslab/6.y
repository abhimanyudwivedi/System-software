%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B
%%
S:A A A A A A A A A A X B;
X:A X |;
%%
int main()
{
	printf("enter the string\n");
	yyparse();
	printf("\nstring is valid\n");
}
int yyerror()
{
	printf("\nthe string is invalid");
	exit(0);
}
