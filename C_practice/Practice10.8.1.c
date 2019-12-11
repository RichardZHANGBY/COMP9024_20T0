#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	int isRepeat[10] = {0};
	long number;
	
	printf("Enter a number:");
	scanf("%ld", &number);
	
	while (number > 0){
		isRepeat[(long)number%10]++;
		number /= 10;
	}
	
	for (int i = 0; i < 10; i++){
		if (isRepeat[i] > 1){
			printf(" %d ", i);
		}
	}
	
	return 0;
}