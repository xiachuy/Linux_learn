#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int fd = open("fifo",O_RDONLY);
    if(fd == -1)
    {
        perror("read");
        return 0;
    }

     int len = 0;

    while(1)
    {
        char buf[1024]={0};
        int len = read(fd, buf, sizeof(buf));
        if(len == 0)
        {
            printf("写端断开\n");
            exit(0);

        }
        printf("rec buf :%s\n",buf);
    }

    close(fd);
}