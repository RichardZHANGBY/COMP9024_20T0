#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	char ch, message[100];
	int charlen;
	
	printf("Enter a message:");
	for (charlen = 0; (ch = getchar()) != '\n'; charlen++){
		message[charlen] = ch;
	}
	
	printf("\nReversal is : ");
	for (;charlen != -1; charlen--){
		putchar(message[charlen]);
	}
}