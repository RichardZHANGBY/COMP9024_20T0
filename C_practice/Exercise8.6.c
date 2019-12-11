#include <stdio.h>

int digit(int n, int k);

int main(int argc, char *argv[]) {
	printf("%d", digit(123456789, 1));
	printf("%d", digit(123456789, 6));
	printf("%d", digit(123456789, 11));
}

int digit(int n, int k){
	while (k != 1){
		if (n == 0){
			return 0;
		}
		n /= 10;
		k--;
	}
	return n % 10;
}