#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
int main(int argc,char * argv[])
{
    if(argc < 2)
    {
        printf("%s filename\n",argv [0]);
        return -1;
    }

    struct stat stbuf;
    int ret = stat(argv[1],&stbuf);
    if(ret == -1)
    {
        perror("stat");
        return -1;
    }

    //文件类型
    char perms[11]={0};

    switch(stbuf.st_mode & S_IFMT)
    {
        case S_IFLNK: perms[0]= 'l';break;
        case S_IFDIR: perms[0]= 'd';break;
        case S_IFREG: perms[0]= '-';break;
        case S_IFBLK: perms[0]= 'b';break;
        case S_IFCHR: perms[0]= 'c';break;
        case S_IFSOCK: perms[0]= 's';break;
        case S_IFIFO: perms[0]= 'p';break;
        default: perms[0]= '?';break;
    }
    //判断访问权限
    perms[1] = stbuf.st_mode & S_IRUSR ? 'r' :'-' ;
    perms[2] = stbuf.st_mode & S_IWUSR ? 'w' :'-' ;
    perms[3] = stbuf.st_mode & S_IXUSR ? 'x' :'-' ;    
     
    perms[4] = stbuf.st_mode & S_IRGRP ? 'r' :'-' ;
    perms[5] = stbuf.st_mode & S_IWGRP ? 'w' :'-' ;
    perms[6] = stbuf.st_mode & S_IXGRP ? 'x' :'-' ;    

    perms[7] = stbuf.st_mode & S_IROTH ? 'r' :'-' ;
    perms[8] = stbuf.st_mode & S_IWOTH ? 'w' :'-' ;
    perms[9] = stbuf.st_mode & S_IXOTH ? 'x' :'-' ; 

    //硬链接
    int link_num = stbuf.st_nlink;

    //文件所有者
    char * fileuser = getpwuid(stbuf.st_uid)->pw_name;

    char * filegroup = getgrgid(stbuf.st_gid)->gr_name;

    //文件大小

    long int filesize =stbuf.st_size;

    char    mtime[1048];
    char * time = ctime(&stbuf.st_mtime);
    strncpy(mtime,time,strlen(time)-1);

    char buf[1099];
    
    sprintf(buf,"%s %d %s %s %ld %s %s",perms,link_num,fileuser,filegroup,filesize,mtime,argv[1]);

    printf("%s\n",buf);
    return 0;
}