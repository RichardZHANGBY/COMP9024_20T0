// By Mushan, 20T0
//https://github.com/mushanshanshan

#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"


void breadthFirstSearch(Graph g, int src) {
	int visited[GraphNumVertices(g)];
	int v;
	Queue q = QueueNew();
	QueueEnqueue(q, src);
	
	for (int i = 0; i < GraphNumVertices(g); i++){
		visited[i] = 0;
	}
	visited[src] = 1;
	while(!QueueIsEmpty(q)){
		v = QueueDequeue(q);
		printf("%d ", v);
		
		for (int i=0; i < GraphNumVertices(g); i++){
			if (!visited[i] && GraphIsAdjacent(g, v, i)) {
				QueueEnqueue(q, i);
				visited[i] = 1;
			}
		}

	}
	QueueFree(q);
	
}

