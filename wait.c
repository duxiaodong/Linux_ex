/*
 *本程序利用wait等待一个进程
 *2014年 02月 27日 星期四 21:10:44 CST
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    pid_t pid ;
    char *message ;
    int n ;
    int exit_code ;
    printf ("fork program starting\n") ;
    pid = fork () ;
    switch(pid){
        case -1 :
            perror ("fork fail") ;
            exit (1) ;
            break ;
        case 0 :
            message = "this is a child" ;
            n=3 ;
            exit_code =37 ;
            break ;
        default :
            message = "this is a parent" ;
            n=1 ;
            exit_code = 0;
            break ;
    }
    for ( ; n>0 ; n--){
        puts (message);
        sleep (1);
    }
    if (pid !=0 ){
        int stat_val ;
        pid_t child_pid ;
        child_pid = wait(&stat_val) ;
        printf ("Child is finish: PID =%d\n",child_pid) ;
        if (WIFEXITED(stat_val))
            printf ("child exit %d\n",WEXITSTATUS(stat_val));
        else 
            printf("clid terminated");
    }
    exit (exit_code);
}









