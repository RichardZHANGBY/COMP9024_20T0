// Linked Flist implementation ... COMP9024 19T3

//Modified by Mushan in 2020X0
//Linked list for float&&string type

#include "forderlinklist.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct FNode {
	char   url[30];
	float  pagerank; 
	struct FNode *next;
} FNode;

FNode *makeFNode(char *str, float pagerank) {
	FNode *new = malloc(sizeof(FNode));
	assert(new != NULL);
	strcpy(new->url, str);
	new->pagerank = pagerank;
	new->next = NULL;
	return new;
}

//Search a url and return the it's pointer
Flist finLL(Flist L, char *url) {
	if (L == NULL)
		return NULL;
	if (!strcmp(L->url, url))
		return L;
	return finLL(L->next, url);
}

//Insert a url and pagerank
Flist finsertFNode(Flist L, char *str, float pagerank) {
	
	//Find the position that the node should be inserted
	struct FNode *previous = finLL(L, str);
	if(previous != NULL){
		previous->pagerank++;
		return L;
	}
	
	struct FNode *FNode = makeFNode(str, pagerank);
	struct FNode *n = L;
	
	while(n != NULL && n->pagerank >= pagerank){
		
		previous = n;
		n = n ->next;
	}
	
	//If the node shoule be inserted on the head
	if(previous == NULL){
		L = FNode;
		FNode->next = n;
	}
	
	//If the node shoule be inserted on other position	
	else{
		previous->next = FNode;
		FNode->next = n;
	}
	return L;
}

//If a url include a word, the pagerank of the url +1
void faddSelf(Flist L, char *str){
	Flist fp = L;
	
	
	//Search the position of the url and pagerank++
	while (fp != NULL) {
		if(!strcmp(fp->url, str)){
			fp->pagerank++;
		}
		fp = fp->next;
	}
}

void ffreeLL(Flist L) {
	if (L != NULL) {
		ffreeLL(L->next);
	}
	free(L);
}

//Print the result of the search
void fshowUrl(Flist L, int min){
	Flist lp = L;
	
	//Set the maxmum of print times
	int time = 30;
	
	//set i as the maxmun of pagerank
	//If you search 5 word, we should print the urls which pagerank between 5-6 order by pagerank
	//and then print the url which between 4-5 order by pagerank
	//until we reach 1-2 which means only contain 1 word or reach 60 print times
	for(int i = min-1; i >=1; i--){
		while (lp->next != NULL && time >0) {
			if (lp->pagerank >i && lp->pagerank < i+1){
				printf("%s\n", lp->url);
				time--;
			}
			lp = lp->next;
		}
		if (lp->pagerank >i && lp->pagerank < i+1 && time > 0){
			printf("%s\n", lp->url);
			time--;
		}

		lp = L;
	}
}
