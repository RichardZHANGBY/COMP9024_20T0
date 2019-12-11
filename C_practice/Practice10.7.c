#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_DIGITS 10

int digits[3][MAX_DIGITS * 4];
const int segements[10][7] = {
			{1, 1, 1, 1, 1, 1, 0}, /* 0 */
			{0, 1, 1, 0, 0, 0, 0}, /* 1 */
			{1, 1, 0, 1, 1, 0, 1}, /* 2 */
			{1, 1, 1, 1, 0, 0, 1}, /* 3 */
			{0, 1, 1, 0, 0, 1, 1}, /* 4 */
			{1, 0, 1, 1, 0, 1, 1}, /* 5 */
			{1, 0, 1, 1, 1, 1, 1}, /* 6 */
			{1, 1, 1, 0, 0, 0, 0}, /* 7 */
			{1, 1, 1, 1, 1, 1, 1}, /* 8 */
			{1, 1, 1, 1, 0, 1, 1}  /* 9 */
};

void clear_digits_arrary(void);
void process_digit(int digit, int position);
void print_digits_arrary(void);

void clear_digits_arrary(void){
	for (int row = 0; row < 3; row++){
		for (int col = 0; col <MAX_DIGITS*4; col++){
			digits[row][col] = ' ';
		}
	}
}

void process_digit(int digit, int position){
	for (int i = 0; i < 7; i++){
		if (segements[digit][i] == 1){
			switch (i) {
				case 0:
					digits[0][position * 4 + 1] = '_';
					break;
				case 1:
					digits[1][position * 4 + 2] = '|';
					break;
				case 2:
					digits[2][position * 4 + 2] = '|';
					break;
				case 3:
					digits[2][position * 4 + 1] = '_';
					break;
				case 4:
					digits[2][position * 4] = '|';
					break;
				case 5:
					digits[1][position * 4] = '|';
					break;
				case 6:
					digits[1][position * 4 + 1] = '_';
					break;			
			}
		}
	}
}


void print_digits_arrary(void){
	for (int row = 0; row < 3; row++){
		for (int col = 0; col <MAX_DIGITS*4; col++){
			putchar(digits[row][col]);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	char ch;
	
	clear_digits_arrary();
	printf("Enter a number:");
	for(int num_len = 0;(ch = getchar()) != '\n'; num_len++){
		if (ch >= '0' && ch <= '9'){
			process_digit(ch - '0', num_len);
		}
	}
	print_digits_arrary();
	
}