#include <stdio.h>

int main(void)
{

	int month, day, year;
	printf("Enter a date (mm/dd/yyyy/): ");
	scanf("%d/%d/%d", &month, &day, &year);
	printf("you entered the data %4d%02d%02d\n", year, month, day );

	return 0;

}