/*
 *本函数实现了利用tempnam函数创建一个临时文件
 *tempnam的路径是唯一的的---函数原型void *tempnam (char *ptr)
 FILE *tempfile (void) int fputs (const char*str,FILE *fp)
 *2014年 02月 24日 星期一 19:46:05 CST
 */
#include"apue.h"
int main (void)
{
    char name[L_tmpnam],line[MAXLINE];//定义两个数组
    FILE *fp ;//定义文件流
    printf ("%s\n" ,tempnam(NULL));//利用tempanme创建临时文件
    tempnam(name);//再次创建一个文件
    printf ("%s\n",name) ;//打印文件

    if ((fp = tempfile()) == NULL)//因为tempfile是返回指针类型函数 用tempfile创建临时文件
        err_sys("tempfile error");//
    fputs("one line of output\n",fp);//从临时文件输出
    rewind (fp);//返回读取
    if (fgets(line,sizeof(line),fp) == NULL) //
        err_sys ("fget error");
            fputs (line,stdout);
}
/*没有成功原因是temonam的函数原型不是这样子的*/
