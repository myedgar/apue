typedef char Datatype;
typedef struct node
{
  int adjvex;
  struct node *next;
}edge_node;
typedef struct vnode
{
  Datatype vertex;
  edge_node *first_edge;
}vertex_node;
typedef struct
{
  vertex_node adjlist[M];
  int n, e;
}linked_graph;
