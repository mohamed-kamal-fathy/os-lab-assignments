// CPU-Scheduling-Algorithm-In-C
// First Come First Served(FCFS) Scheduling Algorithm(Non Pre-emptive)

#include<stdio.h>
#include<malloc.h>

int findmax(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int tempat,tempbt,i,j ,n, * bt, * wt, * tat , * at , * ct , * st;
    float avgtat, avgwt;
    printf("\n Enter the number of processes : ");
    scanf_s("%d", &n);

    at = (int*)malloc(n * sizeof(int));
    bt = (int*)malloc(n * sizeof(int));
    wt = (int*)malloc(n * sizeof(int));
    tat = (int*)malloc(n * sizeof(int));
    ct = (int*)malloc(n * sizeof(int));
    st = (int*)malloc(n * sizeof(int));

    printf("\n Enter the arrival time and burst time for each process \n");
    for (i = 0; i < n; i++)
    {
        printf(" Arrival Time for P%d : ", i+1);
        scanf_s("%d", &at[i]);
        printf(" Burst time for P%d : ", i+1);
        scanf_s("%d", &bt[i]);
    }
    // Loop for sorting
    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++) {
            if (at[j] < at[i]) {
                tempat = at[i];
                tempbt = bt[i];
                at[i] = at[j];
                at[j] = tempat;
                bt[i] = bt[j];
                bt[j] = tempbt;
            }
        }
    }
    //--------------
    /*printf("\n PROCESS \t BURST TIME \t ARRIVAL TIME\n");
    printf("----------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf(" P%d \t\t %d \t\t %d \n", i + 1, bt[i], at[i]);
    }
    return 0;*/
    //--------------
    st[0] = at[0];
    wt[0] = 0;
    tat[0] = bt[0];
    ct[0] = bt[0];
    avgwt = wt[0];
    avgtat = tat[0];
    for (i = 1; i < n; i++)
    {
        st[i] = findmax(at[i], ct[i - 1]);
        ct[i] = st[i] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        //wt[i] = wt[i - 1] + bt[i - 1];  //waiting time[p] = waiting time[p-1] + Burst Time[p-1]
        //tat[i] = wt[i] + bt[i];     //Turnaround Time = Waiting Time + Burst Time


        avgwt += wt[i];
        avgtat += tat[i];
    }


    avgwt = avgwt / n;
    avgtat = avgtat / n;

    printf("\n PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("--------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);

    printf("\n \tGAANT CHART \n");
    printf("---------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], i+1, tat[i]);
    }
} 
