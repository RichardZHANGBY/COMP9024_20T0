// By Mushan, 20T0
//https://github.com/mushanshanshan

#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

int furthestReachable(Graph g, int src) {

	int visited[GraphNumVertices(g)];
	int v;
	int dest = src;
	int max = 0;
	int currdistan = 0;

	Queue q = QueueNew();
	QueueEnqueue(q, src);
	
	for (int i = 0; i < GraphNumVertices(g); i++){
		visited[i] = -1;
	}
	visited[src] = src;
	while(!QueueIsEmpty(q)){
		v = QueueDequeue(q);
		for (int i=0; i < GraphNumVertices(g); i++){
			if (visited[i] == -1 && GraphIsAdjacent(g, v, i)) {
				QueueEnqueue(q, i);
				visited[i] = v;
			}
		}
	}
	QueueFree(q);

	for (int i=GraphNumVertices(g); i >= 0; i--){
		v = i;
		currdistan = 0;
		while(v != src && visited[v] >= 0 && visited[v] < GraphNumVertices(g) && currdistan <= GraphNumVertices(g)){
			currdistan++;
			v = visited[v];
		}
		if (currdistan > max && currdistan < GraphNumVertices(g)){
			max = currdistan;
			dest = i;
		}
	}
	

	return dest;
}

