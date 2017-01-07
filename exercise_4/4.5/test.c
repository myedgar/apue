#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
  printf("uid = %d, gid = %d \
euid = %d, egid = %d \n", getuid(), getgid(), geteuid, getegid());
  exit(0);
}
