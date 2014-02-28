/*
 *本程序实现从标准输入复制到标准输出--使用fgets和fputs函数
函数原型char *fgets（char* buf, int n, FILE *fp）成功返回buf
失败或到到文末返回NULL
char fputs(char *buf, FILE *fp)出错返回EOF
 *2014年 02月 24日 星期一 16:36:08 CST
 */
#include "apue.h"
int main(void) 
{y
    char buf[MAXLINE];
    while (fgets (buf,MAXLINE,stdin) == NULL)
        if (fputs (buf,stdout) == EOF)
            err_sys ("stdout error");
    if (ferror (stdin)) 
        err_sys ("stdin error");
    exit (0);

}
