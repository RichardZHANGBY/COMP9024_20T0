#include <stdio.h>

double compute_average_word_length(const char *sentece);

int main(int argc, char *argv[]) {
	char sentence[50];
	
	printf("Enter a sentence:");
	fgets(sentence, 50, stdin);
	
	printf("Average word length: %lf", compute_average_word_length(sentence));
}

double compute_average_word_length(const char *sentece){
	const char *p = sentece;
	int length = 0 , words_num = 0, totalLength = 0;
	
	while (*p) {
		length++;
		if (*p++ == ' '){
			words_num++;
			totalLength += --length;
			length = 0;
		}
	}
	
	return (double) (totalLength + --length)  / (words_num+1);
}