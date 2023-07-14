%{
    #include <stdio.h>
    #include <stdlib.h>
    int id = 0, dig = 0, key = 0, op = 0;
    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;
%}
%token DIGIT ID KEY OP
%%

input;
DIGIT input {dig++;}
| ID input {id++;}
| KEY input {key++;}
| OP input {op++;}
| DIGIT {dig++;}
| ID {id++;}
| KEY {key++;}
| OP {op++;}
;
%%

int main(int argc, char ** argv){
    FILE *myfile = fopen("file1.c", "r");
    if(!myfile){
        printf("I can't open file1.c\n");
        return -1;
    }
    yyin = myfile;
    do{
        yyparse();
    }while(!feof(yyin));
    printf("numbers = %d\n", dig);
    printf("identifiers = %d\n", id);
    printf("keywords = %d\n", key);
    printf("operators = %d\n", op);
    return 0;
}

int yywrap(){
    return 1;
}

int yyerror(){
    printf("Error\n");
    return 1;
}
