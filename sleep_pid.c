#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
  int pid;
  pid=fork();
  if(pid==0)
  {
        printf("Child Process\n");
        printf("Child Process id is %d\n",getpid());
        printf("It’s parent process id is %d\n",getppid()); 
        sleep(5);
        printf("Child Process after sleep=5\n");
        printf("Child Process id is %d\n",getpid());
        printf("It’s parent process id is %d\n",getppid());
  }

  else
  {
        printf("Parent Process\n");
        sleep(10);
        printf("Child Process id is %d\n",getpid());
        printf("It’s parent process id is %d\n",getppid());
        printf("Parent terminates");
  }
  return 0;
}