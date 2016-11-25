%{
#include<stdio.h>
#include<stdlib.h>
%}
%token ALPHA DIGIT
%%
S:ALPHA S1;
S1:DIGIT S1|ALPHA S1|;
%%
int main()
{
	printf("\nenter the expression");
	yyparse();
	printf("\nvalid string\n");
	return 1;
}
int yyerror()
{
	printf("\nstring is invalid\n");
	exit(0);
}
