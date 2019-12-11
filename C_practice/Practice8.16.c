#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	int alpha[26] = {0}, i, word1_len, word2_len;
	char ch;
	
	printf("Enter first word:");
	for (word1_len = 0; (ch = tolower(getchar())) != '\n'; word1_len++){
		alpha[ch - 'a']++;
	}
	
	printf("Enter second word:");
	for (word2_len = 0; (ch = tolower(getchar())) != '\n'; word2_len++){
		alpha[ch - 'a']--;
	}
	
	if (word1_len == word2_len){
		for (i = 0; i< 26; i++){
			if (alpha[i] != 0){
				printf("The words are not anagrams.");
				return 0;
			}
		}
		printf("The words are anagrams.");
		return 0;
	}
	printf("The words are not anagrams.");
	return 0;
	
	
}