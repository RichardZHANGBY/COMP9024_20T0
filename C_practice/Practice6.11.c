#include <stdio.h>

int main(void)
{

	int num, numOfDi;

	printf("Enter a number");
	scanf("%d", &num);

	if (num < 10){
		numOfDi = 1;
	}
	else if (num < 100){
		numOfDi = 2;
	}
	else if (num < 1000){
		numOfDi = 3;
	}
	else 
		numOfDi = 4;

	printf("The number %d has %d digits\n", num, numOfDi);
	return 0;
}