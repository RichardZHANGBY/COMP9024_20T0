#include <stdio.h>

int main(void)
{

	int income;
	float tax;

	printf("Enter your income:");
	scanf("%d", &income);

	if (income < 750)
		tax = income * .01f;
	else if (income < 2250)
		tax = 7.5f + (income - 750) * .02f;
	else if (income < 3750)
		tax = 37.5f + (income - 2250) * .03f;
	else if (income < 5250)
		tax = 82.5f + (income - 3750) * .04f;
	else if (income < 7000)
		tax = 142.5f + (income - 5250) * .05f;
	else
		tax = 230 + (income - 7000) * .06f;

	printf("Tax : %.3f\n", tax);
}