%{
    #include <stdio.h>
    #include "y.tab.h"
    extern yylval;
%}
%%

[ \t];
[+|-|/|=|<|>] {printf("operator is %s\n", yytext); return OP;}
[0-9]+ {yylval = atoi(yytext); printf("number is %d\n", yylval); return DIGIT;}
int|char|bool|float|double|void|long|short|unsigned|signed|struct|union|enum|typedef|sizeof|static|extern|auto|register|volatile|const|inline|restrict|_Bool|_Complex|_Imaginary {printf("keyword is %s\n", yytext); return KEY;}
[a-zA-Z0-9]+ {printf("identifier is %s\n", yytext); return ID;}
. ;
%%