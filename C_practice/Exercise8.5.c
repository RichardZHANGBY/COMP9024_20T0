#include <stdio.h>


int num_digits(int n);

int main(int argc, char *argv[]) {
	printf("%d", num_digits(9999));
	printf("%d", num_digits(99999));
	printf("%d", num_digits(9));
}

int num_digits(int n){
	int num = 0;
	while (n % 10 != 0){
		n /= 10;
		num++;
	}
	return num;
}