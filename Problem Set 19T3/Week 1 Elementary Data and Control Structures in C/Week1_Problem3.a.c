#include <stdio.h>

void some_funciton(int num);

int main(int argc, char *argv[]) {
	int num;
	printf("Enter a number:");
	scanf("%d", &num);
	printf("%d\n", num);
	some_funciton(num);
}

void some_funciton(int num){
	while (num != 1){
		if (num % 2 == 0){
			num /= 2;
		}
		else{
			num = 3 * num + 1;
		}
		printf("%d\n", num);
	}
}