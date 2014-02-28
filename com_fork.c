#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
int main(void)
{
    pid_t child;
    int status;
    printf("This will demostrate how to get child status\n");
    if((child=fork())==-1)
    {
        printf("Fork Error :%d\n",strerror(errno));
        exit(1);
    }
    else if(child==0)
    {
        int i;
        printf("I am the child:%d\n",getpid());
        for(i=0;i<1000000;i++) sin(i);
        i=5;
        printf("I exit with %d\n",i);
        exit(i);
    }
    while((child=wait(&status))==-1)
    if(child==-1)
        printf("Wait Error:%d\n",strerror(errno));
    else if(!status)
        printf("Child %d terminated normally return status is zero\n",
                child);
    else if(WIFEXITED(status))
        printf("Child %d terminated normally return status is %d\n",
                child,WEXITSTATUS(status));
    else if(WIFSIGNALED(status))

        printf("Child %xd terminated due to signal %d znot caught\n",
                child,WTERMSIG(status));
}
