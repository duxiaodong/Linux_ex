/*对每个命令行参数打印其文件类型*/
#include "apue.h"
int main (int argc, char *argv [])
{   
    int i ;
    struct stat buf1 ;
    char *ptr ;

    for (i=1; i<argc; i++){
        printf ("%s: ",argv[i]);
        if (lstat (argv[i], &buf1) <0){
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
