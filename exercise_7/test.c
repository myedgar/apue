#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  int p1;
  printf("X\n");

  while((p1 = fork()) == -1)
  ;
  if(p1 == 0)
    printf("A\n");
  else
    printf("B\n");
  printf("Y\n");
}
