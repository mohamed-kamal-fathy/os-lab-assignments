// CPU-Scheduling-Algorithm-In-C
// Non Pre-emptive Priority Scheduling Algorithm

#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>



void main()
{
    int n, i, * at, * st, * ct, * bt, * wt, * tat, * p, * pt, current_time = 0, completed = 0;
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

    printf("\n Enter the arrival time and the burst time and priority for each process \n");
    for (i = 0; i < n; i++)
    {
        printf("-------------------------");
        printf("\n Arrival time of P%d : ", i+1);
        scanf_s("%d", &at[i]);
        printf(" Burst time of P%d : ", i+1);
        scanf_s("%d", &bt[i]);
        printf(" Priority of P%d : ", i+1);
        scanf_s("%d", &pt[i]);
        p[i] = i+1;
    }
    printf("-------------------------\n");
    //---------------------------------
    wt[0] = 0;
    tat[0] = bt[0];
    while (completed != n)
    {
        //find process with min. burst time in ready queue at current time
        int max_index = -1;
        int maximum = -1;
        for (i = 0; i < n; i++) {
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


        if (max_index == -1)
        {
            current_time++;
        }
        else
        {
            st[max_index] = current_time;
            ct[max_index] = st[max_index] + bt[max_index];
            tat[max_index] = ct[max_index] - at[max_index];
            wt[max_index] = tat[max_index] - bt[max_index];
            

            avgtat += tat[max_index];
            avgwt += wt[max_index];
            completed++;
            is_completed[max_index] = true;
            current_time = ct[max_index];
           
        }
    }
    /*for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pt[j] < pt[pos])
            {
                pos = j;
            }
        }
        temp = pt[i];
        pt[i] = pt[pos];
        pt[pos] = temp;
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }*/

   /* wt[0] = 0;
    tat[0] = bt[0];
    avgwt += wt[0];
    avgtat += tat[0];
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];  //waiting time[p] = waiting time[p-1] + Burst Time[p-1]
        tat[i] = wt[i] + bt[i];     //Turnaround Time = Waiting Time + Burst Time
        avgwt += wt[i];
        avgtat += tat[i];
    }*/


    avgwt = avgwt / n;
    avgtat = avgtat / n;

    printf("\n PROCESS \t PRIORITY \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("--------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \t\t %d \n", p[i]+1, pt[i], bt[i], wt[i], tat[i]);
    }

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);

    printf("\n \tGAANT CHART \n");
    printf("---------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], p[i]+1, tat[i]);
    }
}
