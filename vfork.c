/*
 *本函数利用vfork创建进程 pid_t vfork(void)
 *2014年 02月 26日 星期三 19:08:20 CST
 */
# include "apue.h"
int glob = 9 ;
int main (void)
{
    int var ;
    pid_t pid ;
    var = 88 ;
    printf("before vfork\n");
    if ((pid = vfork()) < 0){ //vfork 创建一个进程，
        err_sys ("vfork error") ;
    }else if (pid == 0 ){
        var++ ;
        glob++ ;
        _exit (0);
    }
    printf ("pid = %d, glob = %d, var = %d\n",getpid(),glob ,var );
}
