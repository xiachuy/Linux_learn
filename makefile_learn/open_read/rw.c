#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    int fd = open("a.txt",O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        return -1;
    }
    int fc = open("a_cp.txt",O_WRONLY | O_CREAT,0664);
    if(fc == -1)
    {
        perror("open");
        return -1;
    }
 
    char buf[1024] ={0};
    //进行读写
    int len = 0;
    while((len = read(fd, buf, sizeof(buf))) > 0) {
        write(fc, buf, len);
    }
    close(fc);
    close(fd);
    return 0;
}


// int main() {

   
//     int srcfd = open("a.txt", O_RDONLY);
//     if(srcfd == -1) {
//         perror("open");
//         return -1;
//     }

//     int destfd = open("cpy.txt", O_WRONLY | O_CREAT, 0664);
//     if(destfd == -1) {
//         perror("open");
//         return -1;
//     }

    
//     char buf[1024] = {0};
//     int len = 0;
//     while((len = read(srcfd, buf, sizeof(buf))) > 0) {
//         write(destfd, buf, len);
//     }

  
//     close(destfd);
//     close(srcfd);


//     return 0;
// }