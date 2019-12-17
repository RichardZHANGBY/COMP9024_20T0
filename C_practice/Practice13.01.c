#include <stdio.h>
#include <string.h>

void input_word(void);

int main(int argc, char *argv[]) {
	
	char current_word[20] = " ", largest_word[20] = " ", smallest_word[20] = " ";
	
	for(;;){
		printf("Enter word: ");
		scanf("%20s", current_word);
		if (strlen(current_word) == 4){
			break;
		}
		if (strcmp(largest_word, " ") == 0){
			strcpy(largest_word, current_word);
			strcpy(smallest_word, current_word);
		}
		if (strcmp(current_word, largest_word) > 0){
			strcpy(largest_word, current_word);
		}
		if (strcmp(current_word, smallest_word) < 0){
			strcpy(smallest_word, current_word);
		}
	}
	
	printf("Largest: %s \nSmallest: %s", largest_word, smallest_word);
}