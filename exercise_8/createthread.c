#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


int* thread(void *arg)
{
  pthread_t newthid;
  int test = 6;
  newthid = pthread_self();
  printf("test=  %d\n", test);
  printf("this is a new thread, thread ID = %lu\n", newthid);
  return NULL;
}

int main(void)
{
  pthread_t thid;
  int status;
  int test = 5;
  printf("test=  %d\n", test);
  printf("main threadID is %lu\n", pthread_self());
  if(pthread_create(&thid, NULL, (void*)thread, NULL) != 0)
  {
    printf("thread creation failed\n");
    exit(1);
  }
  pthread_join(thid, (void*)status);
  exit(0);
}
