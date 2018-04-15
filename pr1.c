#include<stdio.h>
int main()
{
    int reference_string[10], page_faults=0, m, n, s, pages, frames;
    printf("\nEnter total number of pages:\t");
    scanf("%d",&pages);
    printf("\nEnter values of reference string:\n");
    for(m=0;m<pages;m++)
    {
        printf("Value No. [%d]:\t",m+1);
        scanf("%d",&reference_string[m]);
    }
    printf("\nEnter total number of frames:\t");
    {
        scanf("%d",&frames);
    }
    int temp[frames];
    for(m=0;m<frames;m++)
    temp[m]=-1;

    for(m=0;m<frames;m++)
    {
        s=0;
        for(n=0;n<frames;n++)
        {
            if(reference_string[m]==temp[n])
            {
                s++;
                page_faults--;
            }
        }
        page_faults++;
        if((page_faults<=frames)&&(s==0))
        {
            temp[m]=reference_string[m];
        }
        else if(s==0)
        {
            temp[(page_faults-1)%frames]=reference_string[m];
        }
        printf("\n");
        for(n=0;n<frames;n++)
        {
            printf("%d\t",temp[n]);
        }
    }
    printf("\nTotal page faults:\t%d\n",page_faults);
    return 0;
}

