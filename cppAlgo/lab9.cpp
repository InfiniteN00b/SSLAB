// LRU and FIFO
#include<stdio.h>
#include<stdlib.h>

int main(){
    int ch, l, f;
    int i, j = 0, k, m,  flag = 0, count = 0, top = 0;
    char F[10], s[25];
    printf("Enter no of empty frames: ");
    scanf("%d", &f);
    printf("Enter length of string: ");
    scanf("%d", &l);
    printf("Enter the string: ");
    scanf("%s", s);
    for(int i = 0; i < f; i++)
        F[i] = -1;

    printf("1. FIFO\n2. LRU\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch(ch){
        case 1: //FIFO
            // int i, j = 0, k, flag = 0, count = 0;
            printf("\n\tPage\t  Frame\t\t\t Faults");
            for(i = 0; i < l; i++){
                for(k = 0; k < f; k++)
                    if(F[k] == s[i]) flag = 1;
                
                if(flag == 0){
                    printf("\n\t%c\t", s[i]);
                    F[j] = s[i];
                    j++;

                    for(k = 0; k < f; k++)
                        printf("    %c", F[k]);
                    printf("\tPage Fault %d", count);
                    count++;
                }
                else{
                    flag = 0;
                    printf("\n\t%c\t", s[i]);
                    for(k = 0; k < f; k++)
                        printf("    %c", F[k]);
                    printf("\tNo Page Fault");
                }
                if(j == f) j = 0;
            }
            break;
        case 2://lru
            // int i, j = 0, k, m, flag = 0, count = 0, top = 0;
            printf("\n\tPage\t  Frame\t\t\t Faults");

            for(i = 0; i < l; i++){
                for(k = 0; k < f; k++){
                    if(F[k] == s[i]){
                        flag = 1;
                        break;
                    }
                }

                printf("\n\t%c\t", s[i]);
                if(j != f && flag != 1){
                    F[top] = s[i];
                    j++;
                    if(j != f) top++;
                }

                else{
                    if(flag != 1){
                        for(k = 0; k < top; k++)
                            F[k] = F[k + 1];
                        F[top] = s[i];
                    }

                    if(flag == 1){
                        for(m = k; m < top; m++)
                            F[m] = F[m + 1];
                        F[top] = s[i];
                    }
                }

                for(k = 0; k < f; k++)
                    printf("    %c", F[k]);
                if(flag == 0){
                    printf("\tPage Fault %d", count);
                    count++;
                }
                else
                    printf("\tNo Page Fault");
                flag = 0;
            }
            break;
        default:
            printf("Invalid choice\n");
            exit(0);
    }

}