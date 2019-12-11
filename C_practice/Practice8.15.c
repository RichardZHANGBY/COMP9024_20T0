#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	char message[80], ch;
	int i, shift, message_len;
	
	printf("Enter message to be encrypted:");
	for (message_len = 0; (message[message_len] = getchar()) != '\n'; message_len++)
		;
		
	printf("Enter shift amount (1-25):");
	scanf("%d", &shift);
	
	printf("Encrypted message:");
	for (i = 0; i < message_len; i++){
		if (message[i] >= 'a' && message[i] <= 'z'){
			putchar(((message[i] - 'a') + shift) % 26 + 'a');
			continue;
		}
		if (message[i] >= 'A' && message[i] <= 'Z'){
			putchar(((message[i] - 'A') + shift) % 26 + 'A');
			continue;
		}
		putchar(message[i]);
		
	}
	return 0;
	
}