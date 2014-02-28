#include "apue.h"
#define tok_add 5
    void do_line (char *);
    void cme_add (void);
    int  get_token(void);
int main (void)
{
    char line [MAXLINE];
    while (fgets (line,MAXLINE,stdin))
        do_line (line);
    exit (0);
}

char *tok_ptr ;
void do_line(char *ptr)
{
    int cmd ;
    tok_ptr=ptr ;
    while ((cmd = get_token()) > 0){
        switch (cmd){
            case tok_add:
            break ;
        }
    }
}

void cme_add(void)
{
    int token ;
    token = get_token();
}

int get_token(void)
{
    printf ("hello world");
}
