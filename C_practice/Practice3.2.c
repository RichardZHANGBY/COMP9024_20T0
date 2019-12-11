#include <stdio.h>

int main(void)
{

	int itemNum, month, day, year;
	float price;

	printf("Enter item number:");
	scanf("%d", &itemNum);
	printf("Enter unit price:");
	scanf("%f", &price);
	printf("Enter purchase date (mm/dd/yyyy):");
	scanf("%d/%d/%d", &month, &day, &year);

	printf("Item\tUnit\tPurchase\n");
	printf("\tPrice\tDate\n");
	printf("%d\t$%6.2f\t%02d/%02d/%04d\n", itemNum, price, month, day, year);

	return 0;
}