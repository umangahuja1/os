#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t p;
    p = fork();

    if(p==0)
    {
        execl("/home/umang/os/my_client", "my_client", NULL);
    }

    else
    {
        wait(0);
    }
}
