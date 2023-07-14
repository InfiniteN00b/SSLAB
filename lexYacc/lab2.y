%{
// recognise the grammer AnB
%}
%token A B
%%

str: s '\n'
s : x B;
x : A x | A;
%%

int main(){
    printf("Enter the string: ");
    if(!yyparse())
        printf("String is accepted\n");
    else
        printf("String is not accepted\n");
}

int yyerror(){
    printf("Error\n");
    return 0;
}