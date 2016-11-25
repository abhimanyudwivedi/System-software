%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NUM ID
%left '+' '-'
%left '*' '/'
%right UMINUS
%%
stmt:expr;
expr:expr '+' expr
|expr '-' expr
|expr '*' expr
|expr '/' expr
|'('expr')'
|NUM
|ID
|'-' expr %prec UMINUS;
%%
int main()
{
	printf("enter the expression\n");
	yyparse();
	printf("\nthe expression is valid");
	return 1;
}
int yyerror()
{
	printf("the expression is invalid");
	exit(0);
}
