// By Mushan, 20T0
//https://github.com/mushanshanshan

#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

int shortestDistance(Graph g, int src, int dest) {
	int visited[GraphNumVertices(g)];
	int v;
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
	int time = 0;
	while(dest != src){
		if (dest == -1){
			return -1;
		}
		dest = visited[dest];
		time++;
	}
	
	
	return time;
}

