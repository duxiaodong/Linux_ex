/*
 *本函数实现fork函数，验证修改fork的子进程变量
 *不影响父进程的变量:
 *2014年 02月 26日 星期三 18:28:38 CST
 */
# include "apue.h"
int glob = 8 ;
char buf [] = "a write to stdout \n";
int main (void)
{
    int var ;
    pid_t pid ;

    var = 88 ;
    if (write (STDOUT_FILENO,buf,sizeof(buf)-1) !=sizeof(buf)-1) //向标准输出写入字符
        err_sys ("write error") ;
    printf("before fork\n");
    
    if ((pid = fork()) < 0){  //fork创建进程，返回两个值，子进程返回0，父进程返回子进程ID
        err_sys("fork error");
    }else if(pid == 0 ) {
        glob++ ;
        var++  ;
    }else {
        sleep (2) ;
    }
    printf("pid = %d, glob =%d, var = %d\n",getpid(), glob, var );
}
//使用
