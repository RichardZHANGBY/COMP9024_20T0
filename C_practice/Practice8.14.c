#include <stdio.h>
#include <ctype.h>


int main(int argc, char *argv[]) {
	char message[100], endChar;
	int msglen, wordLen = 0;
	
	
	printf("Enter a sentence:");
	for (msglen = 0; (message[msglen] = getchar()) != '\n'; msglen++){
		if (message[msglen] == '!' || message[msglen] == '?' || message[msglen] == '.'){
			endChar = message[msglen];
			msglen--;
		}
	}
	
	printf("\nReversal of sentence:");
	
	for (int i = msglen - 1; i >= 0; i--){
		if (message[i] != ' '){
			wordLen++;
		}
		else{
			for (int l = 1; l <= wordLen; l++){
				putchar(message[i + l]);
			}
			wordLen = 0;
			putchar(' ');
		}
		if (i == 0){
			for (int l = 0; l < wordLen; l++){
				putchar(message[i + l]);
			}
			putchar(endChar);
		}
	}
	
}