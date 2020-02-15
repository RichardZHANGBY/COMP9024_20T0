// Graph ADT interface ... COMP9024 19T3

//Modified by Mushan in 2020X0

#include <stdbool.h>

typedef struct GraphRep *Graph;

// vertices are ints
typedef int Vertex;

// edges are pairs of vertices (end-points)
typedef struct Edge {
	Vertex v;
	Vertex w;
} Edge;

Graph newGraph(int);
int   numOfVertices(Graph);
void  insertEdge(Graph, Edge);
void  removeEdge(Graph, Edge);
bool  adjacent(Graph, Vertex, Vertex);
void  showGraph(Graph);
void  freeGraph(Graph);

// Calculate the outbound of each page/vertics as a list
void  countAdjacent(Graph, int*);