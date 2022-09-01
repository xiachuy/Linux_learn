#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = fork();
    if(pid>0)
    {
        printf("I am parent process,pid====%d\n",getpid());
        waitpid(pid);
    }
    else
    {
        // 
         printf("I am child process,pid====%d,ppid=%d\n",getpid(),getppid());
        // sleep(1);
    }

   int i=0;
    for(i=0;i<3;i++)
    {
        printf("i=%d,pid =%d,ppid=%d\n",i,getpid(),getppid());
    }

    
}