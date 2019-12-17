#include <stdio.h>
#include <ctype.h>

int compute_vowel_count(const char *sentence);

int main(int argc, char *argv[]) {
	char sentence[50];
	
	printf("Enter a sentence:");
	fgets(sentence, 50, stdin);
	
	printf("Your sentence contain %d vowels.", compute_vowel_count(sentence));
}

int compute_vowel_count(const char *sentence){
	int count = 0;
	const char *p = sentence;
	
	while(*p){
		if (toupper(*p) == 'A' ||toupper(*p) == 'E' ||toupper(*p) == 'I' ||toupper(*p) == 'O' ||toupper(*p) == 'U'){
			count++;
		}
		p++;
	}
	return count;
}