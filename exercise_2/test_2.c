#include <stdio.h>

int main()
{
  int a, b;
  printf("enter two number:");
  scanf("%d %d",&a,&b);
  printf("%d %d %0.2f",a*b, a/b,(float)(a+b)/2);
  return 0;
}
