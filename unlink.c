/*
 *unlink删除链接的功能----函数原型void unlink（const char *pathname）
 *错误返回-1成功返回0
 *2014年 02月 24日 星期一 21:14:51 CST
 */
#include <apue.h>
#include <fcntl.h>
int main (void)
{
    if( open ("tempfiles",O_RDWR)< 0)
        err_sys ("open error");
    if (unlink ("tempfiles"))
        err_sys ("unlink error");
    printf ("file unlink\n");
    sleep (2);
    printf ("done\n");
    exit (0);




}
