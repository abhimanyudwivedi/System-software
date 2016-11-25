%{
#include"y.tab.h"
%}
%%
[a-z] {return ALPHA;}
[0-9] {return DIGIT;}
. {return yytext[0];}
\n {return 0;}
%%
