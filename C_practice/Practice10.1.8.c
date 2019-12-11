#include <stdio.h>

int main(void)
{

	int numOfDay, startWeek;

	printf("Enter number of days in month:");
	scanf("%d", &numOfDay);
	printf("Enter starting day of the week:");
	scanf("%d", & startWeek);

	for (int i = 2 - startWeek, time = 0; i <= numOfDay; i++, time++){
		if (time != 0 && time % 7 == 0){
			printf("\n");
		}
		if (i <= 0){
			printf("   ");
		}
		else{
			printf("%3d", i);
		}
	}
	printf("\n");
	return 0;
}