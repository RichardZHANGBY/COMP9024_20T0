#include <stdio.h>


int main(int argc, char *argv[]) {
	int number, ten, one;
	char *ONE[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eirht", "nine"};
	char *TEN[10] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	char *TENTY[10] = {"ten", "eleven", "tweleve", "thirteen", "fourteen", "fiteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	
	printf("Enter a number:");
	scanf("%d", &number);
	
	if (number > 99) {
		printf("Error, please enter a number with only two digits.");
		return 0;
	}
	
	one = number % 10;
	ten = (number / 10) % 10;
	
	printf("Your number is: ");
	if (ten == 0){
		printf("%s", ONE[one]);
	}
	if (ten == 1){
		printf("%s", TENTY[one-1]);
	}
	if (ten > 1){
		if (one == 0){
			printf("%s", TEN[ten-1]);
		}
		else{
			printf("%s-%s", TEN[ten-1], ONE[one]);
		}
	}
	puts(".");
}