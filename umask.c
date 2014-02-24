/*2014年 02月 24日 星期一 13:14:18 CST*/
/*foo屏蔽字0 ；bar保留用户读和写其余屏蔽掉*/
#include "apue.h"
#include <fcntl.h>
#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IWOTH)
int main (void)
{
    umask (0);//创建屏蔽字 ,屏蔽掉的权限

    if (creat ("foo",RWRWRW) < 0)
        err_sys("creat error for foo");
    umask (S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if (creat("bar",RWRWRW) < 0)
        err_sys ("creat error for bar") ;
    exit (0);


}
