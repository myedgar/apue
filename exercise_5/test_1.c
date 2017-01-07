#include <stdio.h>

#define MAX(x,y) x^y<<2
int main()
{
  int x = 5, y = 6, z = 7;
  int m;
  m = MAX(x,y);
  m = MAX(m,z);
  printf("%d",m);
  return 0;
}
