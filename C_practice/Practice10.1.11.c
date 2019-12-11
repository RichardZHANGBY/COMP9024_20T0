#include <stdio.h>

int main(void)
{

	int n, e = 1;
	float result = 1;

	printf("Enter the number:");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		e *= i;
		printf("%d\n", e);
		result += (1 / e);
		printf("%f\n", result);
	}


}