/*
 *本程序使用exec系列函数，---exec函数用新进程替换当前进程
 *新进程使用path和file参数指定
 *2014年 02月 27日 星期四 20:27:14 CST
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main ()
{
    printf ("Runing ps with execlp\n") ;
    execlp("ls","ls", "-l", (char*)0) ;//该函数在PATH给定的路径搜索命令，可以直接执行shell内的命令如同 ls-l 
    printf ("Done\n") ;//运行中的程序开始执行execlp调用新程序的代码 ,所以./execlp程序被替换
    exit(0)  ;
}

