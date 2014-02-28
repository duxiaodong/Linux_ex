/*
 *本程序使用exec系列函数，---exec函数用新进程替换当前进程
 *新进程使用path和file参数指定
 *2014年 02月 27日 星期四 20:27:14 CST
 */
#include <unistd.h>
char *const ps_argv[] ={"ps" ,"ax", 0} ;
char *const ps_envp[] ={"PATH=/bin:/usr/bin", "TERM=constsole", 0 };
int execle ("/bin/ps", "ps", "ax", "0");
int execlp ("ps", "ps", "ax", "0") ;
int execle ("/bin/ps", "ps", "ax", "0", "ps_envp") ;

int execv ("/bin/ps", "ps_argv") ;
int execvp("ps", "ps_argv") ;
int execve("/bin/ps", "ps_argv", "ps_envp") ;

