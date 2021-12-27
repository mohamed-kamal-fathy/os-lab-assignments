// CPU-Scheduling-Algorithm-In-C
// Round Robin Scheduling Algorithm(Pre-emptive)

#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int findmax(int a, int b)
{
    return a > b ? a : b;
}


void main()
{
    int n, i, index, qt, * at,* st, * bt, bt_remaining[100], * wt, * ct, * tat,current_time = 0, max_completion_time;
    int completed = 0 , tempat=0 , tempbt=0;
    int queue[100], front = -1, rear = -1;
    float avgwt = 0, avgtat = 0;
    bool visited[100] = { false }, is_first_process = true;
    printf("\n Enter the number of processes : ");
    scanf_s("%d", &n);

    st = (int*)malloc(n * sizeof(int));
    at = (int*)malloc(n * sizeof(int));
    bt = (int*)malloc(n * sizeof(int));
    wt = (int*)malloc(n * sizeof(int));
    ct = (int*)malloc(n * sizeof(int));
    tat = (int*)malloc(n * sizeof(int));

    printf("\n Enter the Quantum Time : ");
    scanf_s("%d", &qt);
    printf("\n Enter the arrival time and the burst time for each process \n\n");
    for (i = 0; i < n; i++)
    {
        printf("-----------------------\n");
        printf(" Arrival time of P%d : ", i+1);
        scanf_s("%d", &at[i]);
        printf(" Burst time of P%d : ", i+1);
        scanf_s("%d", &bt[i]);
        bt_remaining[i] = bt[i];
    }
    printf("-----------------------\n");
    // Loop for sorting
    for (i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) {
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
    //--------------------------------------------------
    wt[0] = 0;
    
    //--------------------------------------------------
    front = rear = 0;
    queue[rear] = 0;
    visited[0] = true;
    while (completed != n)
    {
        index = queue[front];
        //q.pop();
        front++;

        if (bt_remaining[index] == bt[index])
        {
            st[index] = findmax(current_time, at[index]);
            current_time = st[index];
            is_first_process = false;

        }

        if (bt_remaining[index] - qt > 0)
        {
            bt_remaining[index] -= qt;
            current_time += qt;
        }
        else
        {
            current_time += bt_remaining[index];
            bt_remaining[index] = 0;
            completed++;

            ct[index] = current_time;
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];
            avgtat += tat[index];
            avgwt += wt[index];

        }


        //check which new Processes needs to be pushed to Ready Queue from Input list
        for (int i = 1; i < n; i++)
        {
            if (bt_remaining[i] > 0 && at[i] <= current_time && visited[i] == false)
            {
                //q.push(i);
                queue[++rear] = i;
                visited[i] = true;
            }
        }
        //check if Process on CPU needs to be pushed to Ready Queue
        if (bt_remaining[index] > 0)
            //q.push(index);
            queue[++rear] = index;


        //if queue is empty, just add one process from list, whose remaining burst time > 0
        if (front > rear)
        {
            for (int i = 1; i < n; i++)
            {
                if (bt_remaining[i] > 0)
                {
                    queue[rear++] = i;
                    visited[i] = true;
                    break;
                }
            }
        }
    } //end of while
    
   /* for (terminaltime = 0, count = 0; tempn != 0;) {
        initialtime = terminaltime;
        if (tempbt[count] <= qt && tempbt[count] > 0) {
            terminaltime += tempbt[count];
            tempbt[count] = 0;
            wt[count] = terminaltime - bt[count];
            tat[count] = wt[count] + bt[count];
            flag = 1;
        }
        else if (tempbt[count] > qt) {
            tempbt[count] -= qt;
            terminaltime += qt;
        }
        if (tempbt[count] == 0 && flag == 1) {
            tempn--;
            flag = 0;
        }
        if (initialtime != terminaltime) {
            printf(" %d\t|| P%d ||\t%d\n", initialtime, count, terminaltime);
        }
        if (count == n - 1)
            count = 0;
        else
            ++count;
    }*/

    printf("\n \tGAANT CHART \n");
    printf("---------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], i, tat[i]);
    }

    printf("\n PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("-----------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \n", i+1, bt[i], wt[i], tat[i]);
        
    }


    avgwt = avgwt / n;
    avgtat = avgtat / n;

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);
}
