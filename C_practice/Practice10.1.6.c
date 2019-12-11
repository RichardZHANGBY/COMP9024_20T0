#include <stdio.h>

int main(void)
{

	int max;

	printf("Enter the max number:");
	scanf("%d", &max);

	for (int i = 2; i * i <= max; i += 2){
		printf("%d\n", i * i);
	}
}