typedef int datatype;
typedef struct link_node
{
  datatype info;
  struct link_node *next;
} node;
typedef struct
{
  node *front,*rear;
} queue;
queue *init();
int empty(queue qu);
queue *insert(queue *qu, datatype x);
queue *delete(queue *qu);
