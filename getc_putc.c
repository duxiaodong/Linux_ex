/*
 *本程序实现从标准输入到标准输出的复制---按照字节为单位--即使用
 *getc 与putc 并且比较与gets 和puts效率
 *2014年 02月 24日 星期一 16:07:42 CST
 */
# include <stdio.h>
# include "apue.h"
int main (void)
{
    int c ;
    while (c=getc(stdin)== EOF)
        if (putc(c,stdout) == EOF)
            err_sys ("output error");
    if (ferror (stdin))
        err_sys ("input error");

}
