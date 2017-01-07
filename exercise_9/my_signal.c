#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int signo)
{
  printf("recv SIGINT\n");
}

int main()
{
  signal(SIGINT, handle_sigint);
  while(1)
  {
    printf("test\n");
    sleep(1);
  }
  return 0;
}
