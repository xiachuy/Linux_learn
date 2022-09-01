#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
    //fork 前创建
    int pipefd[2];
    int ret = pipe(pipefd);
    if(ret ==-1)
    {
        perror("pipe");
        return -1;
    }

    int fd =fork();
    if(fd>0)
    {
        
          close(pipefd[1]);
          char buf[1024] ={0};
          int len =-1;
          while((len =read(pipefd[0],buf,sizeof(buf)))>0)
          {
    
            printf("%s",buf);
            memset(buf,0,1024);
          }
       
    }
    else if(fd == 0)
    {      
    
        //文件描述符的重定向
        close(pipefd[0]);
        dup2(pipefd[1],STDOUT_FILENO);
        execlp("ps","ps","aux",NULL);
        perror("execlp");

     
    }

    return 0;
}