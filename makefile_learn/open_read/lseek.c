#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd = open("a.txt",O_RDWR);
    if(fd == -1)
    {
        perror("open");
    }
    int res=lseek(fd,10,SEEK_END);
    if(res == -1)
    {
        perror("lseek");
    }
    write(fd," ",1);
    close(fd);
    return 0;
}

