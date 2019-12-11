#include <stdio.h>

int main(void)
{

	int first, second, third;

	printf("Enter phone number:");
	scanf("(%d) %d-%d", &first, &second, &third);

	printf("You entered %d.%d.%d\n", first, second, third);
	return 0;
}