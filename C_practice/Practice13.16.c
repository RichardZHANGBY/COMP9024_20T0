#include <stdio.h>
#include <string.h>

void reserver(char *message);

int main(int argc, char *argv[]) {
	char message[50];
	printf("Enter a message:");
	fgets(message, 50, stdin);
	if (message[strlen(message) - 1] == '\n') {
		message[strlen(message) - 1] = '\0';
	}
	reserver(message);
	printf("The reserver: %s", message);
}

void reserver(char *message){
	char *p1 = message, *p2 = message, *p3 = message, ch;
	
	while(*p2++)
	;
	for(p2 -= 2;p2 - p1 > 0;p1++, p2--){
		ch = *p2;
		*p2 = *p1;
		*p1 = ch;
	}
}