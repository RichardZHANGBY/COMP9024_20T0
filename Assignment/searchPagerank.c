//Author: Mushan
//Data: 2020X0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "forderlinklist.h"


char* convertUrl(char*);

int main(int argc, char *argv[]) {
	
	//Initialize variables
	char *token;
	char line[1000];
	char temp[30];
	float tempPagerank;
	int i;
	FILE *pagerankList;
	FILE *fpinv;
	Flist pagerank = NULL;
	
	//Open pagerankList.txt, exit if error
	if((pagerankList = fopen("pagerankList.txt", "r")) == NULL){
		printf("Open pagerankList.txt error!");
		exit(1);
	}
	
	//Read pagerankList.txt and store in pagerank;
	while(fgets(line, 1000, pagerankList) != NULL)  {
		
			//Split string by ',' and ' ,'
			token = strtok(line, ",");
			strcpy(temp, token);
		 	token = strtok( NULL, " ,");
			token = strtok( NULL, " ,");
			tempPagerank = atof(token);
			
			//Store the pageranks in pagerankList
			pagerank = finsertFNode(pagerank, convertUrl(temp), tempPagerank);
		 }
	fclose(pagerankList);
	
	//Open invertedIndex.txt, exit if error
	if((fpinv = fopen("invertedIndex.txt", "r")) == NULL){
		printf("Open invertedIndex.txt error!");
		exit(1);
	}
	
	//Read invertedIndex.txt and compare with the search word
	while(fgets(line, 1000, fpinv) != NULL) {
		
		//Split string by ' '
		token = strtok(line, " ");
		
		//Compare with the search words
		for(i=1; i<argc; i++){
			if(!strcmp(token, argv[i])){
				
				//If the string is the same with the search word
				//Read the urls and ,add the value of the pageranks of thses urls
				token = strtok( NULL, " ");
				while( token != NULL ) {
					convertUrl(token);
					
					//If the url include the word, the pagerank of the url +1
					faddSelf(pagerank, token);
					token = strtok( NULL, " ");
				}
				
			break;
			}
		}
	}
	
	//Print the url with the argc as the max pagerank
	fshowUrl(pagerank, argc);
	
	//Close the file and free memory
	fclose(fpinv);
	ffreeLL(pagerank);
}

//Convert the url without '\n'
char* convertUrl(char* str){
	int len = strlen(str), i, j;
	for(i=0;i<len+1;i++)
	{
		if(str[i] != '\n'){
			continue;
		}
		for(j=i;j<len;j++)
		{
			str[j] = str[j+1];
		}
		len--;
		i--;
	}
	return str;
}
