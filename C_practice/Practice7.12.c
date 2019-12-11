#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	float result, num;
	char ch;
	
	printf("Enter an experssion:");
	scanf("%f", &result);
	
	while ((ch = getchar()) != '\n'){
		switch (ch) {
			case '+':
				scanf("%f", &num);
				result += num;
				break;
			case '-':
				scanf("%f", &num);
				result -= num;
				break;
			case '*':
				scanf("%f", &num);
				result *= num;
				break;
			case '/':
				scanf("%f", &num);
				result /= num;
				break;
			
			
		}
	}
	
	printf("Value of expression: %f", result);
	return 0;
}