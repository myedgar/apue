#include <stdio.h>
#include <stdlib.h>

void creat(linked_graph *g, char *filename, int c)
{
	
  int i, j, k;
  edge_node *s;
  FILE *fp;
  fp = fopen(filename, "r");
  if(fp)
  {
    fscanf(fp,"%d%d",&g->n,&g->e);
    for(i = 0; i < g->n; i++)
    {
      fscanf(fp,"%1s", &g->adjlist[i].vertex);
      g->adjlist[i].first_edge = NULL;
    }    
    for(k = 0; k < g->e; k++)
    {  
      fscanf(fp,"%d%d",&i, &j);
      s = (edge_node *)malloc(sizeof(edge_node));
      s->adjvex = j;
      s->next = g->adjlist[i].first_edge;
      g->adjlist[i].fist_edge = s;
      if(c == 0)
      {
	s = (edge_node *)malloc(sizeof(edge_node));
	s->adjvex = i;
	s->next = g->adjlist[j].first_edge;
	g->adjlist[j].first_edge = s;
      }
    }
    fclose(fp);
  }
  else
    g->n = 0;
}
