#include "apue.h"

void   pr_stdio(const char *, FILE *);
int    is_unbuffered(FILE *);
int    is_linebuffered(FILE *);
int    buffer_size(FILE *);

int main()
{
  FILE *p;

  fputs("enter any character\n", stdout);
  if(getchar() == EOF)
    err_sys("getchar error");
  fputs("one line to standard error\n", stderr);

  pr_stdio("stdin", stdin);
  pr_stdio("stdout", stdout);
  pr_stdio("stderr", stderr);

  if()
}
