#include <stdio.h>

int main(int argc, char *argv[]) {
	int num[25], i, sum;
	
	printf("Enter row 1:");
	for (i = 0; i < 5; i++){
		scanf(" %d", &num[i]);
	}
	printf("Enter row 1:");
	for (; i < 10; i++){
		scanf(" %d", &num[i]);
	}
	printf("Enter row 1:");
	for (; i < 15; i++){
		scanf(" %d", &num[i]);
	}
	printf("Enter row 1:");
	for (; i < 20; i++){
		scanf(" %d", &num[i]);
	}
	printf("Enter row 1:");
	for (; i < 25; i++){
		scanf(" %d", &num[i]);
	}
	
	printf("Row totals:");
	for (i = 0; i < 5; i++){
		sum = 0;
		for (int count = 0; count < 5; count++){
			sum += num[i * 5 + count];
		}
	printf(" %d", sum);
	}
	
	printf("\nRow totals:");
	for (i = 0; i < 5; i++){
		sum = 0;
		for (int count = 0; count < 5; count++){
			sum += num[i + count * 5];
		}
	printf(" %d", sum);
	}
}