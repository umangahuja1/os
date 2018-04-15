#include<stdio.h>

int main()
{
    int i,j,sum=0,n,last;
    int d[20];
    int disk;   
    int temp,max;
    int dloc;  
    printf("Enter number of location: ");
    scanf("%d",&n);
    printf("Enter position of head: ");
    scanf("%d",&disk);
    printf("Enter max value of cylinder: ");
    scanf("%d",&max);
    printf("Enter elements of disk queue: \n");
    for(i=0;i<n;i++)
    {
    scanf("%d",&d[i]);
    }
    d[n]=disk;
    n=n+1;
    for(i=0;i<n;i++)    
    for(j=i;j<n;j++)
    {
        if(d[i]>d[j])
        {
        temp=d[i];
        d[i]=d[j];
        d[j]=temp;
        }
    }
    
    printf("Order : ");
    for(i=0;i<n;i++)   
    {
    if(disk==d[i]) { dloc=i; last = disk; break;  }
    }
    for(i=dloc;i>0;i--)
    {
        printf("%d  ",d[i-1]);
        sum += last-d[i-1];
        last = d[i-1];
    }
    sum+=d[0];
    last = 0;
    printf("0 ");
    for(i = dloc+1;i<n;i++)
    {
        printf("%d  ",d[i]);
        sum += d[i]-last;
        last = d[i];
    }
    printf("\nTotal Tracks Displaced: %d\n",sum);
    return 0;
}