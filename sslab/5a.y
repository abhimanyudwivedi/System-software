%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NUM
%left '+' '-'
%left '*' '/'
%%
exp:E {printf("the value of the expression is %d\n",$1);}
E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {if($3==0)
printf("invalid");
else
$$=$1/$3;}
|NUM
|'-'E {$$=-$2;};
%%
int main()
{
	printf("\nenter an expression\n");
	yyparse();
	printf("\nvalid expression\n");
}
int yyerror()
{
	printf("string is invalid");
	exit (0);
}
