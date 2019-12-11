#include <stdio.h>

int main(void)
{

	int x, result;
	printf("Please enter x: \n");
	scanf("%d", &x);
	result = ((((3 * x + 2) * x - 5 ) * x + 7) * x - 6);

	printf("The result is: %d\n" ,  result);
	return 0;
}