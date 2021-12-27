// CPU-Scheduling-Algorithm-In-C
// Shortest Job First(SJF) Scheduling Algorithm(Non Pre-emptive)

#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

void main()
{
    int n, * bt, * wt, * tat, * p , * ct , * at , * st;
    float avgwt = 0, avgtat = 0;
    bool is_completed[100] = { false };
    int current_time = 0, completed = 0;
    printf("\n Enter the number of processes : ");
    scanf_s("%d", &n);

    p = (int*)malloc(n * sizeof(int));
    at = (int*)malloc(n * sizeof(int));
    st = (int*)malloc(n * sizeof(int));
    bt = (int*)malloc(n * sizeof(int));
    wt = (int*)malloc(n * sizeof(int));
    tat = (int*)malloc(n * sizeof(int));
    ct = (int*)malloc(n * sizeof(int));

    printf("\n Enter the arrival time and the burst time for each process \n");
    for (int i = 0; i < n; i++)
    {
        printf(" arrival time for P%d : ", i + 1);
        scanf_s("%d", &at[i]);
        printf(" Burst time for P%d : ", i+1);
        scanf_s("%d", &bt[i]);
        p[i] = i+1;
    }
    while (completed != n)
    {
        //find process with min. burst time in ready queue at current time
        int min_index = -1;
        int minimum = 32999;
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && is_completed[i] == false) {
                if (bt[i] < minimum) {
                    minimum = bt[i];
                    min_index = i;
                }
                if (bt[i] == minimum) {
                    if (at[i] < at[min_index]) {
                        minimum = bt[i];
                        min_index = i;
                    }
                }
            }
        }

        if (min_index == -1)
        {
            current_time++;
        }
        // Calculations
        else
        {
            st[min_index] = current_time;
            ct[min_index] = st[min_index] + bt[min_index];
            tat[min_index] = ct[min_index] - at[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];

            avgtat += tat[min_index];
            avgwt += wt[min_index];

            completed++;
            is_completed[min_index] = true;
            current_time = ct[min_index];
        }
    }
    // >>>>>>>>>>>>> Calculate avg waiting / avg turnaround
    avgwt = avgwt / n;
    avgtat = avgtat / n;
    // >>>>>>>>>>>>> print results
    printf("\n PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);

    printf("\n \tGAANT CHART \n");
    printf("-------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], p[i], tat[i]);
    }
}
