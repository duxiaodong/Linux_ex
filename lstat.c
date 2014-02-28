/*
 *本函数实现从命令输入参数打印其文件类型
 *lstat函数原型 --int lstat (const char *pathname, struct stat *buf)
 *struct stat 结构体类型包含文件的基本形式
2014年 02月 24日 星期一 21:22:42 CST
 */
#include "apue.h"
int main (int argc, char *argv [])
{   
    int i ;
    struct stat buf1 ;
    char *ptr ;

    for (i=1; i<argc; i++){
        printf ("%s: ",argv[i]);
        if (lstat (argv[i], &buf1) <0){ //调用lstat 应注意后面的结构体需要加&
            err_ret ("lstat error");
        continue ;
    }
    if (S_ISREG(buf1.st_mode)) 
        ptr ="reguar file";
    else if (S_ISDIR(buf1.st_mode))
        ptr ="director file";
    else if (S_ISCHR(buf1.st_mode))
        ptr ="char file";
    else if (S_ISBLK(buf1.st_mode))
        ptr ="block special";
    else
        ptr ="unkown";
		printf("%s\n", ptr);

}
    exit(0) ;

}
