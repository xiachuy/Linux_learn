#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    int ret = mkfifo("fifo",0664);
    if(ret == -1)
    {
        perror("mkfifo");
        return -1;
    }
}