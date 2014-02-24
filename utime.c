/*
 *利用open将文件截断为0，但并不更改文件访问时间,利用utime函数
 *2014年 02月 24日 星期一 13:57:05 CST
 */
#include "apue.h"
#include <utime.h>
#include <fcntl.h>
int main (int argc ,char *argv [])
{
    int i , fd ;
    struct stat statbuf ;
    struct utimbuf timebuf ;

    for (i=1 ;i<argc; i++){
        if ((stat(argv[i],&statbuf))<0){
            err_ret ("%s :stat error",argv[i]);
            continue ;

        }
        if(fd=open("argv[i]",O_RDWR|O_TRUNC) <0){
            err_ret ("%s :open error",argv[i]);
            continue ;
        }
        close (fd);
        timebuf.actime = statbuf.st_atime ;
        timebuf.modtime = statbuf.st_mtime ;
        if (utime(argv[i],&timebuf) <0){
            err_ret ("%s :utime error",argv[i]);
        }
        exit (0);

    }
}
