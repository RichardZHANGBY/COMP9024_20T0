//Author: Mushan
//Data: 2020X0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "graph.h"

int checknumOfUrl();
int convertUrl2Int(char *urllist[], char *url);
void linkGraph(Graph graph, char *url, char *urllist[]);
void calPageRank(Graph graph, double *pagerank, float damFactor, float diffPR, float maxIterations, int *numOfAdj);
void sort(double *a, int *b, int lenofa);



int main(int argc, char *argv[]) {
	//Check the number of factor
	if (argc != 4){
		printf("Factor ERROR!");
		exit(1);
	}
	
	//Calculate the number of URL
	int numOfUrl=checknumOfUrl(), i, n;
	
	//Initialize variables
	char *urllist[numOfUrl];
	Graph graph = newGraph(numOfUrl);
	float damFactor = atof(argv[1]);
	float diffPR = atof(argv[2]);
	double pagerank[numOfUrl];
	int maxIterations = atoi(argv[3]);
	int numOfAdj[numOfUrl];
	int sortedPagerank[numOfUrl];
	FILE *fpwrite, *fp;
	
	for (i=0; i<numOfUrl; i++){
		pagerank[i] = 0.0;
		sortedPagerank[i] = 0;
	}
	
	//Read the URLs and number the URLs
	if ((fp = fopen("collection.txt", "r")) != NULL){
		for(i=0; i<numOfUrl; i++){
			urllist[i] = malloc(30 * sizeof(char));
			assert(urllist[i] != NULL);
			fscanf(fp, "%s", urllist[i]);
			sortedPagerank[i] = i;
		}
		fclose(fp);
	}
	else{
		printf("Open collection.txt error!");
		//Free the graph and array
		freeGraph(graph);
		for(i=0; i<numOfUrl; i++){
			free(urllist[i]);
		}
		exit(1);
	}
	
	//Draw the graph
	for(int i=0; i<numOfUrl; i++){
		linkGraph(graph, urllist[i], urllist);
	}
	
	//Count the number of adjacent vertical of each vertical
	countAdjacent(graph, numOfAdj);
	
	//Calculate the pageranks of each URLs
	calPageRank(graph, pagerank, damFactor, diffPR, maxIterations, numOfAdj);
	
	//Sort the list of pageranks by pagerank
	sort(pagerank, sortedPagerank, numOfUrl);
	
	//Write the pageranks to the "pageranklist.txt"
	if((fpwrite = fopen("pagerankList.txt", "w")) != NULL){
		for(int i=0; i<numOfUrl; i++){
			n = sortedPagerank[i];
			fprintf(fpwrite, "%s, %d, %.7f\n", urllist[n], numOfAdj[n], pagerank[i]);
		}
		fclose(fpwrite);
	}
	else{
		printf("Open pagerankList.txt error!");
		//Free the graph and array
		freeGraph(graph);
		for(i=0; i<numOfUrl; i++){
			free(urllist[i]);
		}
		
		exit(1);
	}
	
	
	//Free the graph and array
	freeGraph(graph);
	
	for(i=0; i<numOfUrl; i++){
		free(urllist[i]);
	}
	
	return 0;
	
}

	//Return the number of URL
int checknumOfUrl(){
	int num = 0;
	char url[30];
	FILE *fp;
	if((fp = fopen("collection.txt", "r")) != NULL){
		while(fscanf(fp, "%s", url) != EOF){
			num++;
		}
		fclose(fp);
	}
	
	return num;
}

	//Search the index of URL in urllist
int convertUrl2Int(char *urllist[], char *url){
	for(int i=0;; i++){
		if(strcmp(url, urllist[i]) == 0){
			return i;
		}
	}
	return -1;
}


	//Read the urlfiles and draw the graph
void linkGraph(Graph graph, char *url, char *urllist[]){
	char tempurl[30], temp[30];
	Edge e;
	int read = 0;
	
	//Create a copy of curr url
	strcpy(tempurl, url);
	
	//Read URL.txt
	FILE *fp = fopen(strcat(tempurl, ".txt"), "r");
	while(fscanf(fp, "%s", temp) != EOF){
		//Cheak the endpoint
		if(!strcmp(temp, "#end")){
			fclose(fp);
			return;
		}
		//Insert the edges while reading the urlfiles
		if(read){
			e.v = convertUrl2Int(urllist, url);
			e.w = convertUrl2Int(urllist, temp);
			insertEdge(graph, e);
		}
		//Cheak the startpoint
		if(!strcmp(temp, "Section-1")){
			read = 1;
		}
	}
}


	//Calculate pageranks for each page
void calPageRank(Graph graph, double *pagerank, float damFactor, float diffPR, float maxIterations, int *numOfAdj){
	int i, k, itertimes = 0;
	float diff = 10.0;
	double temppagerank[numOfVertices(graph)];
	
	//Set the pageranks of each url as 1/numofVetices at the 1st iteration
	for(i=0; i<numOfVertices(graph); i++){
		pagerank[i] = 1.0 / numOfVertices(graph);
	}
	
	//Cheak the diff & iteration times
	while(itertimes < maxIterations && diff >= diffPR){
		itertimes++;
		diff = 0;
		
		//Calculate The first part (1-d)/N
		for(i=0; i<numOfVertices(graph); i++){
			temppagerank[i] = (1.0 - damFactor) / numOfVertices(graph);
			
			//Calculate The second part the sum of other pagerank influence
			for(k=0; k<numOfVertices(graph); k++){
				if (k != i && adjacent(graph, k, i)){
					temppagerank[i] += pagerank[k] / numOfAdj[k] * damFactor;
				}
			}
		}
		
		//Calculate the diff
		for(i=0; i<numOfVertices(graph); i++){
			diff += fabs(temppagerank[i] - pagerank[i]);
			pagerank[i] = temppagerank[i];
		}
	}	
}
	
	//Calculate the print order by pagerank
void sort(double *pagerank, int *sortpagerank, int lenofpagerank){
	int i, j, temp;
	double lftemp;

	for(j=0; j<lenofpagerank; j++){
		for(i=0; i<lenofpagerank-j;i++){
			if(pagerank[i] < pagerank[i+1]){
				lftemp = pagerank[i];
				pagerank[i] = pagerank[i+1];
				pagerank[i+1] = lftemp;
				temp = sortpagerank[i];
				sortpagerank[i] = sortpagerank[i+1];
				sortpagerank[i+1] = temp;
			}
		}
	}

}