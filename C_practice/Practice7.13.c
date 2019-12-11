#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	int total = 0, spaces = 0;
	char ch;
	
	printf("Enter a sentence:");
	while ((ch = getchar()) != '\n'){
		total++;
		if (ch == ' '){
			spaces++;
		}
	}
	
	printf("Average word length: %.1f", (float) (total - spaces) / (spaces + 1));
}