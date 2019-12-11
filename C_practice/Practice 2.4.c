#include <stdio.h>

int main(void)
{

	float amount;
	printf("Enter an amout:\n");
	scanf("%f", &amount);
	amount = amount * 1.05f;
	printf("With tax added: $%.2f\n", amount);
	return 0;
}