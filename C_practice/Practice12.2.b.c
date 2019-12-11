#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char message[100], ch, *p, *s;
	
	printf("Enter a message:");
	for (p = &message[0]; (*p = toupper(getchar())) <= 'Z' && *p >= 'A'; p++)
	;
	p--;
	for (s = &message[0]; s < p; s++, p--){
		if (*s != *p){
			printf("Not a palindrome");
			exit(0);
		}
	}
	printf("Palindrome");
}