#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int rea = access("fifo",F_OK);
    if(rea == -1)
    {
        printf("管道不存在\n");
        int ret = mkfifo("fifo",0664);
        if(ret == -1)
        {
            perror("mkfifo");
            return -1;
        }

    }

    int fd  = open("fifo",O_WRONLY);
    if(fd == -1)
    {
         perror("open");
         return -1;
    }
    for(int i=0;i<100;i++)
    {
        char buf[1024];
        sprintf(buf,"hello,%d\n",i);
        printf("write data :%s\n",buf);
        write(fd,buf,strlen(buf));
        sleep(1);

    }

    close(fd);
}