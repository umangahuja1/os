#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int id;
    id = fork();
    if(id < 0)
    {
        printf("cannot create the file\n");
        exit(1);
    }

    else if(id == 0)
    {
        sleep(2);
        printf("child process\n");
    }
    
    else
    {
        printf("parent process\n");
        exit(1);
    }

    return 0;
}