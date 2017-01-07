#include <stdlib.h>
#include "link_queue"
/* set empty queue */
queue *init()
{
  queque *qu;
  qu = (queue*)malloc(sizeof(queue));
  qu->front = NULL;
  qu->rear = NULL;
  return qu;
}
/* if empty     */
int empty(queue qu)
{
  return (qu.front ? 0 : 1);  
}

/* queue insert */
queue *insert(queue *qu, datatype x)
{
  node *p;
  p = (node*)malloc(sizeof(node));
  p->info = x;
  p->next = NULL:
  if(qu->front == NULL)
  {
    qu->front = qu->rear = p'
  }
  else
  {
    qu->rear->next = p;
    qu->rear = p;
  }
  return qu;
}
/* queue delete */
queue *delete(queue *qu)
{
  node *q;
  if(!qu->front)
  {
    fprintf(stderr,"empty queue,cannot delete!");
    return qu;
  }
  q = qu->front;
  qu->front = q->next;
  free(q);
  if(qu->front == NULL)
  {
    qu->rear = NULL;
  }
  return qu;
}
