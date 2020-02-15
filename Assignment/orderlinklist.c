// Linked list implementation ... COMP9024 19T3

//Modified by Mushan in 2020X0
//Linked list for string type

#include "orderlinklist.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
	char   value[30];
	struct Node *next; 
	struct Node *word;
} Node;

Node *makeNode(char *str) {
	Node *new = malloc(sizeof(Node));
	assert(new != NULL);
	strcpy(new->value, str);
	new->next = NULL;
	new->word = NULL;
	return new;
}

//Search the position of a specific node and return the pointer
List inLL(List L, char *str) {
	if (L == NULL)
		return NULL;
	if (strcmp(L->value, str) == 0)
	  return L;

	return inLL(L->next, str);
}

//Insert a word
List insertWord(List L, char *str) {
	
	//Initialize variables and make a node
	struct Node *node = makeNode(str);
	struct Node *previous = NULL;
	struct Node *n = L;
	
	//Find the position that the node should be inserted
	while(n != NULL && strcmp(n->value, node->value) <0){
		previous = n;
		n = n ->next;
	}
	
	//If the node shoule be inserted on the head	
	if(previous == NULL){
		L = node;
		node->next = n;
	}
	
	//If the node shoule be inserted on other position	
	else{
		previous->next = node;
		node->next = n;
	}
	
	return L;
}

//Insert a url of a word
List insertUrl(List L, char *word, char *url){
	
	//Search the position of the word
	List n = inLL(L, word);
	
	//Insert the url into the word's orderlinklist
	if (!inLL(n->word, url)){
		n->word = insertWord(n->word, url);
	}
	return L;
}

//Print the linklist
void showLL(List L) {
	if (L == NULL)
		putchar('\n');
	else {
		printf("%s ", L->value);
		
		//If L is a word, then print it's url
		showUrl(L->word);
		
		showLL(L->next);
	}
}

//Print urls that contain a specific word
void showUrl(List L) {
	if (L == NULL)
		putchar('\n');
	else {
		printf("%s ", L->value);
		showUrl(L->next);
	}
}

//Write the linklist to a file
void writeLL(FILE *fp, List L){
	if (L == NULL)
		return;
	else {
		fprintf(fp, "%s ", L->value);
		
		//If L is a word, then write it's url
		writeUrl(fp, L->word);
		
		writeLL(fp, L->next);
	}
}

//Write the urls that contain a specific word to a file
void writeUrl(FILE *fp, List L) {
	if (L == NULL)
		fprintf(fp, "\n");
	else {
		fprintf(fp, " %s", L->value);
		writeUrl(fp, L->next);
	}
}


void freeLL(List L) {
	if (L != NULL) {
		freeLL(L->next);
		freeLL(L->word);
		free(L);
	}
}
