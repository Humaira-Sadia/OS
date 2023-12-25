#include <stdio.h>
#include <stdlib.h>

struct sjf
{
    int pid, atime, btime, ctime, ttime, wtime;
};

struct sjf p[10];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    float tot, awt;

    printf("Enter the number of processes : ");
    scanf("%d", &n);

    printf("SJF SCHEDULING...");
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("\nProcess %d: \nEnter Arrival Time: ", p[i].pid);
        scanf("%d", &p[i].atime);
        printf(" \nEnter Burst Time: ");
        scanf("%d", &p[i].btime);
    }

    // Sorting....
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].atime > p[j + 1].atime)
            {
                swap(&p[j].atime, &p[j + 1].atime);
                swap(&p[j].btime, &p[j + 1].btime);
                swap(&p[j].pid, &p[j + 1].pid);
            }
            else if (p[j].atime == p[j + 1].atime)
            {
                if (p[j].btime > p[j + 1].btime)
                {
                    swap(&p[j].atime, &p[j + 1].atime);
                    swap(&p[j].btime, &p[j + 1].btime);
                    swap(&p[j].pid, &p[j + 1].pid);
                }
            }
        }
    }

    // Calculation...

    int k = p[0].atime;
    for (int i = 0; i < n; i++)
    {
        k = k + p[i].btime;
        if (k < p[i].atime)
            k = p[i].atime + p[i].btime;
        p[i].ctime = k;
        p[i].ttime = p[i].ctime - p[i].atime;
        p[i].wtime = p[i].ttime - p[i].btime;
        tot += p[i].ttime;
        awt += p[i].wtime;
    }

    printf("DATA SET\n");
    printf("PID\tATIME\tBTIME\tCTIME\tTTIME\tWTIME\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t %d\t %d\t %d\t %d\t %d\t\n", p[i].pid, p[i].atime, p[i].btime, p[i].ctime, p[i].ttime, p[i].wtime);
    }

    printf("\n Average Total Time : %.2f", tot / n);
    printf("\n Average Waiting Time : %.2f", awt / n);
}