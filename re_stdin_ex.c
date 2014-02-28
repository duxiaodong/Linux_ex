/*
 *程序功能从标准输入读入命令并且执行--类似与bash shell的功能
 *2014年 02月 26日 星期三 19:24:48 CST
 */
# include "apue.h"
# include <sys/wait.h>
int main (void)
{
    char buf [MAXLINE];//定义数组存放标准输入的字符
    pid_t pid ;//定义进程ID 
    int status ;
    printf("%% ") ;
    while (fgets (buf,MAXLINE,stdin) != NULL){ //标准IO函数从标入命令
        if (buf[strlen(buf)-1] =='\n')
            buf[strlen(buf)-1] = 0;//没搞明白
        if ((pid = fork ()) < 0 ){ //创建子进程
            err_sys ("fork error");
        }else if (pid == 0 ){ //子进程返回值  
            execlp( buf, buf, (char *) 0) ;//子进程调用execle用来执行新的程序， ( char*) 0
            err_ret ("couldnot execute :%s", buf);
            exit (127) ;
        }
        if (( pid = waitpid (pid , &status,0)) < 0) //子进程调用execle执行新程序，父进程等待子进程终止 
            err_sys("waitpid error");
        printf ("%% ");
    }
    exit (0);
}
