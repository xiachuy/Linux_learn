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
    }
    else
    {
    
        execl("hello","hello",NULL);
         printf("I am parent process\n");
    }

    int i=0;
    for(i=0;i<3;i++)
    {
        printf("i=%d,pid =%d\n",i,getpid());
    }
    return 0;
}