#include <stdio.h>
#include "Stack.h"

int main(int argc, char *argv[]) {
	int num;
	printf("Enter a number:");
	scanf("%d", &num);
	while (num != 0){
		push(num%2);
		num /= 2;
	}
	while (!isEmpty()){
		printf("%d", pop());
	}
}