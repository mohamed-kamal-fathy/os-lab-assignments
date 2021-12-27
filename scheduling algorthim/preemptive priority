// CPU-Scheduling-Algorithm-In-C
// Pre-emptive Priority Scheduling Algorithm

#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int main()
{

    int i, n, * bt, bt_remaining[100], * wt, * tat, * p, * ct, * at, * st, * pt, current_time = 0, completed = 0;
    float avgwt = 0, avgtat = 0;
    bool is_completed[100] = { false };
    printf("\n Enter the number of processes : ");
    scanf_s("%d", &n);

    p = (int*)malloc(n * sizeof(int));
    at = (int*)malloc(n * sizeof(int));
    st = (int*)malloc(n * sizeof(int));
    bt = (int*)malloc(n * sizeof(int));
    pt = (int*)malloc(n * sizeof(int));
    wt = (int*)malloc(n * sizeof(int));
    ct = (int*)malloc(n * sizeof(int));
    tat = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("------------------------\n");
        printf(" Arrival time for P%d : ", i + 1);
        scanf_s("%d", &at[i]);
        printf(" Burst time for P%d : ", i + 1);
        scanf_s("%d", &bt[i]);
        bt_remaining[i] = bt[i];
        printf(" Priority time for P%d : ", i + 1);
        scanf_s("%d", &pt[i]);
        p[i] = i + 1;
    }
    printf("------------------------\n");
    while (completed != n)
    {
        //find process with min. burst time in ready queue at current time
        int max_index = -1;
        int maximum = -1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && is_completed[i] == 0) {
                if (pt[i] > maximum) {
                    maximum = pt[i];
                    max_index = i;
                }
                if (pt[i] == maximum) {
                    if (at[i] < at[max_index]) {
                        maximum = pt[i];
                        max_index = i;
                    }
                }
            }
        }

        // printf("max Index=%d ",max_index);
        if (max_index == -1)
        {
            current_time++;
        }
        else
        {
            if (bt_remaining[max_index] == bt[max_index])
                st[max_index] = current_time;

            bt_remaining[max_index]--;
            current_time++;

            if (bt_remaining[max_index] == 0)
            {
                st[max_index] = current_time;
                ct[max_index] = st[max_index] + bt[max_index];
                tat[max_index] = ct[max_index] - at[max_index];
                wt[max_index] = tat[max_index] - bt[max_index];


                avgtat += tat[max_index];
                avgwt += wt[max_index];
                completed++;
                is_completed[max_index] = true;

                printf("Max=%d ", ct[max_index]);
            }
        }
    }
    /*for (int i = 0; i < n; i++)
    {
        printf("%.2d ", ct[i]);
    }
    printf("\n%.2f", avgtat / n);
    printf("\n%.2f", avgwt / n);*/
    avgwt = avgwt / n;
    avgtat = avgtat / n;

    printf("\n PROCESS \t PRIORITY \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("--------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \t\t %d \n", p[i], pt[i], bt[i], wt[i], tat[i]);
    }

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);

    printf("\n \tGAANT CHART \n");
    printf("---------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], p[i], tat[i]);
    }
    return 0;
}
