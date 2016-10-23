%{
	#include<stdio.h>
	int op=0,id=0,cb=0,a=0,s=0,d=0,m=0,ob=0,flag=1;
%}
%%
[a-z A-Z][a-z A-Z 0-9] {id++;printf("\n%s is an identifier",yytext);}
"+" {op++;a++;printf("\t%s is an operator",yytext);}
"-" {op++;s++;printf("\t%s is an operator",yytext);}
"*" {op++;m++;printf("\t%s is an operator",yytext);}
"/" {op++;d++;printf("\t%s is an operator",yytext);}
"(" {ob++;}
")" {if(ob=cb+1) cb++;
	 else flag=0;
	}
.	{;}
%%
int main()
{
	printf("\n enter an expression");
	yylex();
	if((id==op+1)&&(ob==cb)&&(flag==1))
	{
		printf("\nvalid expression\n");
	}
	else
	{
		printf("\ninvalid expression\n");
	}
	return 0;
}	
