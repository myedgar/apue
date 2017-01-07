#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t pid;
  char *msg = NULL;
  int k;
  int stat_val;  
  printf("Process Creation Study\n");
  pid = fork();
  if(pid < 0)
    perror("Process creation failed");
  else if(pid == 0)
  {
    msg = "Child process is running";
    k = 7;
  }
  else
  {
    msg = "Parent process is running";
    k = 6;
  }
  while(k > 0)
  {
    puts(msg);
    sleep(1);
    k--;
  }
  wait(&stat_val);
  exit(0);
}

