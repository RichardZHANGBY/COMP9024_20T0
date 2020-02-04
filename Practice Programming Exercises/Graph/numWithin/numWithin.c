
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

int checkMinimal(int *prev, int len){
	int min = -1, i, num;
	
	for (i=0; i<len; i++){
		if ( prev[i] != -2 && prev[i] != -1 && ( min == -1 || min > prev[i])){
			min = prev[i];
			num = i;
		}
	}
	return num;
}

int numWithin(Graph g, int src, int dist) {
	int prev[GraphNumVertices(g)];
	int distance[GraphNumVertices(g)];
	int i;
	int vertic;
	int nextv;
	
	for (i = 0; i < GraphNumVertices(g); i++){
		prev[i] = -1;
		distance[i] = -1;
	}
	prev[src] = 0;
	
	for (i = 0; i < GraphNumVertices(g); i++){
			vertic = checkMinimal(prev, GraphNumVertices(g));
			distance[vertic] = prev[vertic];
			prev[vertic] = -2;
			
			for (nextv = 0; nextv < GraphNumVertices(g); nextv++){
				if (GraphIsAdjacent(g, vertic, nextv) && nextv != vertic && prev[nextv] != -2){
					if (prev[nextv] == -1){
						prev[nextv] = distance[vertic] + 1;
					}
					else if (prev[nextv] > distance[vertic] + 1){
						prev[nextv] = distance[vertic] + 1;
					}
				}
			}
		}
	
	for (i=0, vertic=0; i < GraphNumVertices(g); i++){
		if (distance[i] <= dist){
			vertic++;
		}
	}
	
	return vertic;
}

