#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define _LINE_ 100

void my_err(const char *err_string, int line)
{
  fprintf(stderr,"line:%d ", line);
  perror(err_string);
  exit(1);
}

int my_read(int fd)
{
  int len;
  int ret;
  int i;
  char read_buf[64];
  
  if(lseek(fd, 0, SEEK_END) == -1)
  {
    my_err("lseek", _LINE_);
  }
  if((len = lseek(fd, 0, SEEK_CUR)) == -1)
  {
    my_err("lseek", _LINE_);
  }
  if(lseek(fd, 0, SEEK_SET) == -1)
  {
    my_err("lseek", _LINE_);
  }
  printf("len:%d\n", _LINE_);
  if((ret = read(fd, read_buf, len)) < 0)
  {
    my_err("read", _LINE_);
  }
  for(i = 0; i<len; i++)
  {  
    printf("%c", read_buf[i]);
  }
  printf("\n");
  return ret;
}

int main()
{
  int fd;
  char write_buf[32] = "hello world!";

  if((fd = open("example_63.c", O_RDWR|O_CREAT, S_IRWXU)) == -1)
  {
    my_err("open", _LINE_);
  }
  else
  {
    printf("creat file success\n");
  }
  
  if(write(fd, write_buf, strlen(write_buf)) != strlen(write_buf))
  {
    my_err("open", _LINE_);
  }
  my_read(fd);
  close(fd);
  return 0;
}
