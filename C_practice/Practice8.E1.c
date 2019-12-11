#include <stdio.h>

int main(void)
{

	int low_rate, num_year;
	float value[5];

	printf("Enter interest rate:");
	scanf("%d", &low_rate);
	printf("Enter number of years: ");
	scanf("%d", &num_year);

	printf("\nYears");
	for (int i = 0; i < 5; i++){
		printf("%6d%%", low_rate + i);
		value[i] = 100.0f;
	}

	printf("\n");
	for (int year = 1; year <= num_year; year++){
		printf("%4d   ", year);
		for (int i = 0; i < (int) (sizeof(value) / sizeof(value[0])); i++){
			value[i] *=  ((float)(low_rate + i) / 100 + 1);
			printf("%7.2f", value[i]);
		}
		printf("\n");
	}
	
}