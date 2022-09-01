#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int ret =access("a.txt",F_OK);
    if(ret == -1)
    {
        perror("access");
    }
    int rec = chmod("a.txt",0775);
    if(rec == -1)
    {
        perror("chmod");
    }
    int retr = truncate("a.txt",30);
    if(rec == -1)
    {
        perror("truncate");
        return -1;
    }
    printf("文件存在");
}