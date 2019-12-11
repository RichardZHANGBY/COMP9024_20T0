#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	char firstChar, ch;
	
	printf("Enter a first and last name:");
	firstChar = getchar();
	while (getchar() != ' ');
	while ((ch = getchar()) != '\n'){
		putchar(ch);
	}
	printf(" %c.", firstChar);
	return 0;
}