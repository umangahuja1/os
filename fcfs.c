#include <stdio.h>

struct process{
    int id,wait,ser,tottime;
}p[20];

int main()
{
    int i,j,n,totalwait=0,totalser=0,avgturn,avgwait;
    printf("Enter the number of processes : ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("\nEnter process id : ");
        scanf("%d", &p[i].id);
        printf("Enter process service time : ");
        scanf("%d", &p[i].ser);
    }

    p[1].wait=0;
    p[1].tottime = p[1].ser;

    for(i=2;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            p[i].wait += p[j].ser;
        }

        totalwait += p[i].wait;
        p[i].tottime = p[i].wait + p[i].ser;
        totalser += p[i].tottime;   
    }

    avgturn = totalser/n;
    avgwait = totalwait/n;

    printf("\nId\tService\tWait\tTotal");
    for(i=1;i<=n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\n", p[i].id, p[i].ser, p[i].wait, p[i].tottime);
    }

    printf("\nAverage turnaround time : %d", avgturn);
    printf("\nAverage waiting time : %d\n",avgwait);

}