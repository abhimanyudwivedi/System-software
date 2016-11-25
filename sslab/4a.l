%{
#include"y.tab.h"
%}
%%
[0-9]+ {return NUM;}
[a-zA-Z][0-9a-zA-Z]* {return ID;}
. {return yytext[0];}
\n {return 0;}
%%
