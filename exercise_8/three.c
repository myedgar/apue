#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;;
int global = 0;

void* thread1(void* arg)
{
  pthread_cleanup_push(pthread_mutex_unlock, &mutex);
  while(1)
  {
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond, &mutex);
    printf("thread1's gloabl is %d\n",++global);
    pthread_mutex_unlock(&mutex);
    sleep(1);
  }
  pthread_cleanup_pop(0);
  return NULL;
}
void* thread2(void* arg)
{
  pthread_cleanup_push(pthread_mutex_unlock, &mutex);
  while(1)
  {
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond, &mutex);
    printf("thread2's gloabl is %d\n",++global);
    pthread_mutex_unlock(&mutex);
    sleep(2);
  }
  pthread_cleanup_pop(0);
  return NULL;
}
void* thread3(void* arg)
{
  pthread_cleanup_push(pthread_mutex_unlock, &mutex);
  while(1)
  {
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond, &mutex);
    printf("thread3's gloabl is %d\n",++global);
    pthread_mutex_unlock(&mutex);
    sleep(3);
  }
  pthread_cleanup_pop(0);
  return NULL;
}


int main(void)
{
  pthread_t tid1, tid2, tid3;
  int status;
  printf("the main thread is running \n");
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond, NULL);
  pthread_create(&tid1, NULL, thread1, NULL);
  pthread_create(&tid2, NULL, thread2, NULL);
  pthread_create(&tid3, NULL, thread3, NULL);
  do
  { 
    pthread_cond_signal(&cond);
  }while(1);
  pthread_join(tid1, (void*)status);
  pthread_join(tid2, (void*)status);
  pthread_join(tid3, (void*)status);
  printf("the thread is over\n");  
  pthread_exit(0);
}
