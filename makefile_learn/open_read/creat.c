#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    int fd = open("a1.txt",O_RDONLY | O_CREAT,0777);
    if(fd == -1)
    {
        perror("open");
    }
    printf("O_RDONLY=======%d\n",O_RDONLY);
    printf("O_CREAT=======%d\n",O_CREAT);
    close(fd);
    return 0;
}