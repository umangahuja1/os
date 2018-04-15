#include <iostream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main()
{
    pid_t p = fork();
    if(p==0)
    {
        cout<<"\nchild process\nhello\n";
        cout<<"process id : "<<getpid()<<endl;
        cout<<"parent id : "<<getppid()<<endl;
        cout<<"child id : "<<p<<endl;        
        cout<<endl;
    }
    else if(p>0)
    {
        cout<<"\nparent process\nhello\n";
        cout<<"process id : "<<getpid()<<endl;
        cout<<"parent id : "<<getppid()<<endl;
        cout<<"child id : "<<p<<endl;        
        cout<<endl;
        

        
    }
}