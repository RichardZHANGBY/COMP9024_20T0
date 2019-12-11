#include <stdio.h>

int main(void)
{

	int grade, fstDig;
	printf("Enter numerical grade:");
	scanf("%d", &grade);

	if (grade < 0 || grade > 100){
		printf("Error grade.\n");
		return 0;
	}

	fstDig = grade / 10;

	printf("Letter grade: ");
	switch (fstDig){
		case 10: 
		case 9:
				printf("A\n");
				break;
		case 8:
				printf("B\n");
				break;
		case 7:
				printf("C\n");
				break;
		case 6:
				printf("D\n");
				break;
		default:
				printf("F\n");
				break;


	}

	return 0;

}