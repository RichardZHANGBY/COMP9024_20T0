// By Mushan, 20T0
//https://github.com/mushanshanshan

#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Stack.h"

int visited[1000];

bool dfsCycleCheck(Graph g, int prev, int curr) {
	visited[curr] = true;
	
	int n;
	
	for (n = 0; n < GraphNumVertices(g); n++){
		if (GraphIsAdjacent(g, curr, n)){
			if (!visited[n]){
				if (dfsCycleCheck(g, curr, n)){
					return true;
				}
			}
			else if (n != prev){
				return true;
			}
		}
	}
	return false;
}

bool hasCycle(Graph g) {
	int i, v = GraphNumVertices(g);
	
	for (i = 0; i < v; i++){
		visited[i] = false;
	}
	
	for (i = 0; i < v; i++){
		if (!visited[i]){
			if (dfsCycleCheck(g, i, i)){
				return true;
			}
		}
		
	}
	
	return false;
}
