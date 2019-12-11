#include <stdio.h>

int main(void)
{

	int total,amountOf20,amountOf10,amountOf5,amountOf1;

	printf("Enter a dollar amount:\n");
	scanf("%d", &total);

	amountOf20 = total / 20;
	total = total - 20 * amountOf20;
	amountOf10 = total / 10;
	total = total - 10 * amountOf10;
	amountOf5 = total / 5;
	total = total - 5 * amountOf5;
	amountOf1 = total;

	printf("$20 bills: %d\n", amountOf20);
	printf("$10 bills: %d\n", amountOf10);
	printf(" $5 bills: %d\n", amountOf5);
	printf(" $1 bills: %d\n", amountOf1);

	return 0;

}