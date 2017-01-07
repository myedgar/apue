#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char **environ)
{
  pid_t pid;
  int stat_val;
  printf("Exec example!\n");
 
  pid = fork();
  if(pid > 0)
  {
    printf("Parent process is running\n");
  }
  else if(pid == 0)
  {
    printf("Child process is running\n");
    printf("My pid = %d,parentpid = %d\n", getpid(), getppid());
    printf("uid = %d,gid = %d\n", getuid(), getgid());
    execve("processimage",argv,environ);
    printf("process never go to here!\n");
    exit(0);
  }
  else
  {
    perror("Process Creation failed\n");
    exit(1);
  }
  wait(&stat_val);
  exit(0);
}
