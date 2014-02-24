#include <apue.h>
#include <fcntl.h>
int main (void)
{
    if( open ("tempfiles",O_RDWR)< 0)
        err_sys ("open error");
    if (unlink ("tempfiles"))
        err_sys ("unlink error");
    printf ("file unlink\n");
    sleep (2);
    printf ("done\n");
    exit (0);




}
