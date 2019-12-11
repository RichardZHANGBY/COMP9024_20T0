#include <stdio.h>

int main(void)
{

	int hour, minute;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hour, &minute);

	if (hour >= 12 && !(hour == 12 && minute == 0)){
		printf("Equivalent 12-hour time: %d:%02d PM\n", hour-12, minute);
	}
	else
		printf("Equivalent 12-hour time: %d:%02d AM\n", hour, minute);

	return 0;
}

[print('bin bin is a nice boy')