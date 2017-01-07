#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_key_t key;

void* thread2(void* arg)
{
  int tsd = pthread_self();
  printf("thread2 %lu is running\n", pthread_self());
  pthread_setspecific(key, (void*)tsd);
  printf("thread2 %lu returns %d\n", pthread_self(), pthread_getspecific(key));
  printf("fuck!");
  pthread_exit(0);
}

void* thread1(void *arg)
{
  int tsd = 0;
  int status;
  pthread_t thid2;

  printf("thread1 %lu is running\n", pthread_self());
//  pthread_setspecific(key, (void*)tsd);
  pthread_create(&thid2, NULL, thread2, NULL);
  printf("shit!\n");
  printf("thread1 %lu returns %d\n", pthread_self(), pthread_getspecific(key));
  pthread_join(thid2, (void*)&status);
  pthread_exit(0);
}

int main()
{
  int sta;
  pthread_t thid1;
  printf("main thread is runnning \n");
  pthread_key_create(&key, NULL);
  pthread_create(&thid1, NULL, thread1, NULL);
  pthread_join(thid1, (void*)&sta);
  pthread_key_delete(key);
  printf("main thread exit\n");
  return 0;
}

