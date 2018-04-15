#include <unistd.h>
#include <stdio.h>

int main()
{
    int i,n;
    printf("Enter the value of n : ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        printf("%d\n",i+1);
    }
}