// Integer Stack ADO tester ... COMP9024 19T3 
#include <stdio.h> 
#include <stdlib.h> 
#include "Stack.h"

int main(void) {

	int i, n;
	char str[BUFSIZ];

	initstack();
	printf("Enter a positive number: "); 
	scanf("%s", str); 
	if ((n = atoi(str)) > 0) { 
		// convert to int and test if positive 
		for (i = 0; i < n; i++) { 
			printf("Enter a number: "); 
			scanf("%s", str); 
			push(atoi(str)); 
		} 
	}

	while(!isEmpty()){
		printf("%d\n", pop());
	}

	return 0;

}