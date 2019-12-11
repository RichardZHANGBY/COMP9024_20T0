#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	char message[100], ch, *p;
	
	printf("Enter a message:");
	for (p = &message[0]; (ch = getchar()) != '\n';){
		*p++ = ch;
	}
	
	printf("\nReversal is : ");
	while (p >= &message[0]){
		putchar(*p--);
	}
}