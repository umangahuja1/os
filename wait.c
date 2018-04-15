#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
pid_t cpid,ppid;
cpid=getpid();
ppid=getppid();
printf("\nChild Process ID:%d\nParent Process ID:%d\n",cpid,ppid);
cpid=fork();
if(cpid<0)
{
printf("ERROR.\n");
exit(EXIT_FAILURE);
}
else if(cpid==0)
{
printf("A new process has been forked\n");
ppid=getppid();
printf("Press any key to terminate child process....\n");
int a;
scanf("%d",&a);
}
else
{
wait(NULL);
exit(EXIT_SUCCESS);
}
printf("\nChild Process ID: %d\nParent Process ID:%d\n",cpid,ppid);
return 0;
}