#include<math.h>
#include<stdio.h>
int main()
{
    int i,n,j=0,k=0,x=0,l,req[50],mov=0,cp,ub,end,lower[50],upper[50], temp,a[50];
    printf("enter the current position\n");
    scanf("%d",&cp);
    printf("enter the number of requests\n");
    scanf("%d",&n);
    printf("enter the request order\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("Enter the upper bound\n");
    scanf("%d",&ub);

    for(i=0;i<n;i++)
    {
        if(req[i]<cp)
        {
            lower[j]=req[i];
            j++;
        }
        if(req[i]>cp)
        {
            upper[k]=req[i];
            k++;
        }
    }

    for(i=0;i<j;i++)
    {
        for(l=0;l<j-1;l++)
        {
            if(lower[l]<lower[l+1])
            {
                temp=lower[l];
                lower[l]=lower[l+1];
                lower[l+1]=temp;
            }
        }
    }

    for(i=0;i<=k;i++)
    {
        for(l=0;l<k-1;l++)
        {
            if(upper[l]>upper[l+1])
            {
                temp=upper[l];
                upper[l]=upper[l+1];
                upper[l+1]=temp;
            }
        }
    }

    printf("Enter the end to which the head is moving (0 - for lower end(zero) and 1 - for upper end\n");
    scanf("%d",&end);
    switch(end)
    {
        case 0:
            for(i=0;i<j;i++)
            {
                a[x]=lower[i];
                x++;
            }

            for(i=0;i<k;i++)
            {
                a[x]=upper[i];
                x++;
            }
        break;
        case 1:
            for(i=0;i<k;i++)
            {
                a[x]=upper[i];
                x++;
            }

            for(i=0;i<j;i++)
            {
                a[x]=lower[i];
                x++;
            }
        break;
    }

    mov=mov+fabs(cp-a[0]);
    printf("%d -> %d",cp,a[0]);
    for(i=1;i<x;i++)
    {
        mov=mov+fabs(a[i]-a[i-1]);
        printf(" -> %d",a[i]);
    }
    printf("\n");
    printf("total head movement = %d\n",mov);
}