#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	char message[100], ch;
	int meglen;
	
	printf("Enter the message:");
	for (meglen = 0; (message[meglen] = toupper(getchar())) != '\n'; meglen++)
	;
	
	printf("In B1FF-speak:");
	for (int i = 0; i < meglen; i++){
		switch (message[i]) {
			case 'A':
				putchar('4');
				break;
			case 'B':
				putchar('8');
				break;
			case 'E':
				putchar('3');
				break;
			case 'I':
				putchar('1');
				break;
			case 'O':
				putchar('0');
				break;
			case 'S':
				putchar('5');
				break;
			default:
				putchar(message[i]);
				break;
		}
	}
	return 0;
}