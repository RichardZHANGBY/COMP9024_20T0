#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int are_anagrams(const char *word1, const char *word2);

int main(int argc, char *argv[]) {
	char word1[30], word2[30];
	printf("Enter first word:");
	fgets(word1, 30, stdin);
	printf("Enter second word:");
	fgets(word2, 30, stdin);
	
	if (are_anagrams(word1, word2)){
		printf("The words are anagrams");
	}
	else{
		printf("NOT");
	}
	return 0;
}

int are_anagrams(const char *word1, const char *word2){
	int chars[26] = {0};
	const char *p1 = word1, *p2 = word2;
	
	while(*p2){
		chars[toupper(*p2++) - 'A' + 1]++;
	}
	
	while(*p1){
		chars[toupper(*p1++) - 'A' + 1]--;
	}
	for (int i = 0; i < 26; i++){
		if (chars[i] != 0){
			return false;
		}
	}
	return true;
}