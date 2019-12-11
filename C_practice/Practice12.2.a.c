#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char message[100], ch;
	int length;
	
	printf("Enter a message:");
	for (length = 0;(message[length] = toupper(getchar())) <= 'Z' && message[length] >= 'A'; length++)
		;
		length--;
	for (int i = 0; i < length / 2 + 1; i++){
		if (message[i] != message[length - i]){
			printf("Not a palondrome");
			exit(0);
		}
	}
	printf("Palindrome");
}