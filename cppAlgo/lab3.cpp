// LL(1) parsing

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std;

char prod[3][10] = {"A->aBa", "B->bB", "B->@"}, input[10], stack[25];
int top = -1, j = 0, k, l;

void push(char a){
    stack[++top] = a;
}

void pop(){
    top--;
}

void display(){
    for(int i = top; i >= 0; i--)
        printf("%c", stack[i]);
}

void stackpush(char p){
    if(p == 'A'){
        pop();
        for(j = strlen(prod[0]) - 1; j >= 3; j--)
            push(prod[0][j]);
    }
    else{
        pop();
        for(j = strlen(prod[1]) - 1; j >= 3; j--)
            push(prod[1][j]);
    }
}

int main(){
    char c;
    int i;
    printf("Grammer is:\n A->aBa\n B->bB\n B->@\n");
    printf("first(A) = {a}\t follow(A) = {$}\n");
    printf("first(B) = {b, @}\t follow(B) = {a}\n");
    printf("\t a \t b \t $\n");
    printf("A \t A->aBa \t \t \n");
    printf("B \t B->bB \t B->@\n");
    printf("Enter the input string tp parse: ");
    scanf("%s", input);
    for(i = 0; input[i] != '\0'; i++){
        if(input[i] != 'a' && input[i] != 'b' && input[i] != '$'){
            printf("Invalid input string\n");
            exit(0);
        }
    }
    if(input[i - 1] != '$'){
        printf("Input string does not end with $\n");
        exit(0);
    }
    push('$');
    push('A');

    i = 0;
    printf("\nStack\tInput\tAction\n");
    printf("-----\t-----\t------\n");

    while(i != strlen(input) && stack[top] != '$'){
        printf("\n");
        for(l = top; l >= 0; l--)
            printf("%c", stack[l]);
        printf("\t");
        for(l = i; l < strlen(input); l++)
            printf("%c", input[l]);
        printf("\t");

        if(stack[top] == 'A'){
            printf("A->aBa");
            stackpush('A');
        }
        else if(stack[top] == 'B'){
            if(input[i] == 'b'){
                printf("B->bB");
                stackpush('B');
            }
            else{
                printf("B->@");
                pop();
            }
        }
        else {
            if(stack[top] == input[i]){
                printf("pop %c", input[i]);
                printf("\tMatched %c", input[i]);
                pop();
                i++;
            }
            else break;
        }
    }

    if(stack[top] == '$' && input[i] == '$'){
        printf("\n$\t$");
        printf("\nValid string accepetd\n");
    }
    else printf("\nInvalid string\n");

    return 0;
}