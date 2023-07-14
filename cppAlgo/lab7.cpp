// SRTF algorithm and RR

#include<stdio.h>
int main(){
    int count, j, n, time, flag = 0, time_quantum, ch = 0;
    int wait_time = 0, turnaround_time = 0, at[10], bt[10], rt[10];
    int endTime, i, smallest;
    int remain = 0, sum_wait = 0, sum_turnaround = 0;

    printf("1.Round RObin\n2.SRTF\n");
    scanf("%d", &ch);
    printf("Enter no of Processes : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("Enter arrival time for Process P%d : ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for Process P%d : ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    switch(ch){
        case 1: //round robin
                printf("Enter Time Quantum:\t");
                scanf("%d", &time_quantum);
                remain = n;
                printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");

                for(time = 0, count = 0; remain != 0;){
                    if(rt[count] <= time_quantum && rt[count] > 0){
                        time += rt[count];
                        rt[count] = 0;
                        flag = 1;
                    }
                    else if(rt[count] > 0){
                        rt[count] -= time_quantum;
                        time += time_quantum;
                    }

                    if(rt[count] == 0 && flag == 1){
                        remain--;
                        turnaround_time += time - at[count];
                        wait_time += time - at[count] - bt[count];
                        printf("P[%d]\t|\t%d\t|\t%d\n", count + 1, turnaround_time, wait_time);
                        flag = 0;
                    }
                    if(count == n - 1) count = 0;
                    else if(at[count + 1] <= time) count++;
                    else count = 0;
                }
                printf("\nAverage Waiting Time= %f\n", wait_time * 1.0 / n);
                printf("Avg Turnaround Time = %f", turnaround_time * 1.0 / n);
                break;

        case 2: //SRTF
                remain = 0;
                printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
                rt[9] = 9999;

                for(time = 0; remain != n; time++){
                    smallest = 9;
                    for(i = 0; i < n; i++)
                        if(at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0)
                            smallest = i;
                    
                    rt[smallest]--;
                    if(rt[smallest] == 0){
                        remain++;
                        endTime = time + 1;
                        sum_wait += endTime - at[smallest] - bt[smallest];
                        sum_turnaround += endTime - at[smallest];
                        printf("P[%d]\t|\t%d\t|\t%d\n", smallest + 1, sum_turnaround, sum_wait);
                    }
                }
                printf("\nAverage Waiting Time= %f\n", sum_wait * 1.0 / n);
                printf("Avg Turnaround Time = %f", sum_turnaround * 1.0 / n);
                break;

        default: printf("Invalid choice");

    }
    return 0;

}