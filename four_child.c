#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
   int p,q,r,s;
   pid_t getpid(void);
   printf("\n%d\n\n",getpid());
   system("ps");
   p=fork();
   if(p==0)
   {
      printf("\nThis is child process with id %d",getpid());
      printf("\nIt's Parent Process is %d",getppid());
      exit(0);
   }
   else
   {
      wait(0);
      printf("\nThis is Parent process with id %d",getpid());
   }
   q=fork();
   if(q==0)
   {
      printf("\nThis is child process with id %d",getpid());
      printf("\nIt's Parent Process is %d",getppid());
      exit(0);
   }
   else
   {
      wait(0);
      printf("\nThis is Parent process with id %d",getpid());
   }
   r=fork();
   if(r==0)
   {
      printf("\nThis is child process with id %d",getpid());
      printf("\nIt's Parent Process is %d",getppid());
      exit(0);
   }
   else
   {
      wait(0);
      printf("\nThis is Parent process with id %d",getpid());
   }
   s=fork();
   if(s==0)
   {
      printf("\nThis is child process with id %d",getpid());
      printf("\nIt's Parent Process is %d",getppid());
      exit(0);
   }
   else
   {
      wait(0);
      printf("\nThis is Parent process with id %d",getpid());
   }
   puts("\nEND");
   return 0;
}