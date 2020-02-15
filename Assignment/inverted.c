//Author: Mushan
//Data: 2020X0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "orderlinklist.h"

int checknumOfUrl();
List drawList(List, char*);
char* convertWord(char*);


int main(int argc, char *argv[]) {
	
	//Calculate the number of URL
	int numOfUrl = checknumOfUrl();
	
	//Initialize variables
	char  *urlList[numOfUrl];
	char tempUrl[30];
	char temp[30];
	int i;
	int readFactor;
	int numOfList;
	FILE *fp, *fpwrite;
	
	//Create 26 list for words
	//The listofList[0] means the words which start with 'a'
	//The listofList[25] means the words which start with 'z'
	//I think it will be more efficient than using one list.
	List listofList[26] = {NULL};
	
	//Open collection.txt, if error then exit
	if((fp = fopen("collection.txt", "r")) == NULL){
		printf("Open collection.txt error!");
		exit(1);
	}
	
	//Read url from collection.txt
	for(i=0; i<numOfUrl; i++){
		readFactor = 0;
		
		//Store pagename in urlList
		urlList[i] = malloc(30 * sizeof(char));
		assert(urlList[i] != NULL);
		fscanf(fp, "%s", urlList[i]);
		
		//Open url.txt, if error, continue
		strcpy(tempUrl, urlList[i]);
		FILE *fp;
		if((fp = fopen(strcat(tempUrl, ".txt"), "r")) == NULL){
			printf("Open %s error!", tempUrl);
			exit(1);
		}
		
		//Read the section-2
		while(fscanf(fp, "%s", temp) != EOF){
			
			//Check the checkpoint
			if(!strcmp(temp, "#end") || !strcmp(temp, "Section-2")){
				readFactor++;
				continue;
			}
			
			//Read data after "#end Section-1 \n \n #start Section-2"
			if(readFactor == 2){
				convertWord(temp);
				
				//Calculate the num of the list in listofList by initials
				numOfList = (temp[0] - 'a');
				
				if(!inLL(listofList[numOfList], temp)){
					listofList[numOfList] = insertWord(listofList[numOfList], temp);
				}
				insertUrl(listofList[numOfList], temp, urlList[i]);
			}
			
			//Break after 2nd "#end"
			if(readFactor == 3){
				break;		
			}
		}
		fclose(fp);

	}
	fclose(fp);
	
	//Write the data to invertedIndex.txt
	if((fpwrite = fopen("invertedIndex.txt", "w")) != NULL){
		for (i=0; i<26; i++){
			writeLL(fpwrite, listofList[i]);
		}
		fclose(fpwrite);
	}
	else{
		printf("Open invertedIndex.txt error!");
		exit(1);
	}
	for (i=0; i<26; i++){
		freeLL(listofList[i]);
	}
	for(i=0; i<numOfUrl; i++){
			free(urlList[i]);
	}
	
}

//Calculate the number of URL
int checknumOfUrl(){
	int num = 0;
	char url[1000];
	FILE *fp;
	if((fp = fopen("collection.txt", "r")) != NULL){
		while(fscanf(fp, "%s", url) != EOF){
			num++;
		}
		fclose(fp);
	}
	else{
		printf("Open collection.txt error!");
		exit(1);
	}
	
	return num;
}

//Convert word to lower case letters word
char* convertWord(char* str){
	int len = strlen(str), i, j;
	for(i=0;i<len+1;i++)
	{
		
		//If char is lower case letters just skip
		if((str[i]>='a'&&str[i]<='z') || str[i] == '-'){
			continue;
		}
		
		//If char is upper case letters just convert it to lower case
		if(str[i]>='A'&&str[i]<='Z'){
			str[i] -= ('A' - 'a');
			continue;
		}
		
		//If char is not a letter, remove it
		for(j=i;j<len;j++)
		{
			str[j] = str[j+1];
		}
		len--;
		i--;
	}
		
	return str;
}

