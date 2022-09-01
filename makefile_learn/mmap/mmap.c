#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
/*
        void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset); 
    参数 ： addr NULL 映射地址
            length 要映射的长度 获取文件长度 stat lseek
            port PROT_EXEC  Pages may be executed.
                PROT_READ  Pages may be read.
                PROT_WRITE Pages may be written.
                PROT_NONE  Pages may not be accessed.
                要操作映射内存，必须有读权限
            flags ：
                 MAP_SHARED_VALIDATE 自动同步
                 MAP_PRIVATE ：不同步
*/
int main()
{

}