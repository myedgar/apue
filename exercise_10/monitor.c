#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int arg, char* argv[], char** environ)
{
  int fd[2];
  pid_t pid;
  int stat_val;

  if(arg < 2)
  {
    printf("wrong parameters \n");
    exit(0);
  }
  if(pipe(fd))
  {
    perror("pipe failed");
    exit(1);
  }
  
  pid = fork();
  switch(pid)
  {
    case -1:
      perror("fork failed!");
    case 0:
      close(0);
      dup(fd[0]);
      execve();
  }
}
