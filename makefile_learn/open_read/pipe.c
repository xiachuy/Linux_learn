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
          char buf[1024] ={0};
          while(1)
          {
            int len =read(pipefd[0],buf,sizeof(buf));
            printf("%s",buf);
         
            char * strp ="pang";
            write(pipefd[1],strp,strlen(strp));
            sleep(1);//管道默认阻塞
          }
       
    }
    else if(fd == 0)
    {      
        char buf1[1024] ={0};
        while(1)
        {
          char * str ="ping";
          write(pipefd[1],str,strlen(str));
             sleep(1);
          int len =read(pipefd[0],buf1,sizeof(buf1));
          printf("%s\n",buf1);
          sleep(1);//管道默认阻塞
        }
     
    }

    return 0;
}