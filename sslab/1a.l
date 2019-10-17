%{
	int b=0,w=0,l=0,c=0;
%}
%%
[\t] {w++;b++;} #It is to find the number of tabs
[\n] {w++;l++;} 
[" "] {w++;b++;}
[^" "\t\n] {c+=yyleng;}
%%
int main(int argc,char *argv[])
{
	if(argc==2)
	{
		yyin=fopen(argv[1],"r");
		yylex();
		printf("\nThe number of blank spaces= %d,lines= %d, character= %d, words= %d",b,l,c,w);
	}
	else
	{
		printf("\nInappropriate number of arguments");
	}
}
