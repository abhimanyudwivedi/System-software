%{
	#include<stdio.h>
	int flag=0;
%}
%%
" "[aA][nN][dD]" "|" "[bB][uU][tT]" "|" "[oO][rR]" "|" "[nN][oO][tT]" " {flag=1;}
. {;};
%%
int main()
{
	printf("\nenter a statement");
	yylex();
	if(flag == 1)
	printf("\ncompound expression");
	else 
	printf("\nsimple expression");
	return 0;
}
