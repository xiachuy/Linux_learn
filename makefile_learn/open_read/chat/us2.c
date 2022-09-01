#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int rea1 = access("fifo1",F_OK);
    if(rea1 == -1)
    {
        printf("管道不存在\n");
        int ret = mkfifo("fifo1",0664);
        if(ret == -1)
        {
            perror("mkfifo");
            return -1;
        }

    }
    int rea2 = access("fifo2",F_OK);
    if(rea2 == -1)
    {
        printf("管道不存在\n");
        int ret = mkfifo("fifo2",0664);
        if(ret == -1)
        {
            perror("mkfifo");
            return -1;
        }

    }
    //以只读打开管道1
    int fr  = open("fifo1",O_RDONLY);
    if(fr== -1)
    {
         perror("open");
         return -1;
    }
   printf("管道1打开成功\n");
   //以只读打开管道2
    int fw  = open("fifo2",O_WRONLY);
    if(fw == -1)
    {
         perror("open");
         return -1;
    }
    printf("管道2打开成功\n");
    char buf[128];
    while(1)
    {
        //读数据
         memset(buf,0,128);
         int rer =read(fr,buf,128);
        if(rer == -1)
        {
            perror("read");
            break;
        }
        printf("us2 收到:%s\n",buf);

        memset(buf,0,128);
        //从标准获取
        fgets(buf,128,stdin);
        int rew = write(fw,buf,strlen(buf));
        if(rew == -1)
        {
            perror("write");
            exit(0);
        }

        

    }
   

    close(fw);
    close(fr);
}