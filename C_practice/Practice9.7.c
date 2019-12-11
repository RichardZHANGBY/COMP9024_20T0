#include <stdio.h>

int power(int x, int n);

int main(int argc, char *argv[]) {
	printf("%d", power(2,16));
}

int power(int x, int n){
	if (n == 0){
		return 1;
	}
	if (n % 2 == 1){
		return x * power(x, n-1);
	}
	else{
		return power(x, n/2) * power(x, n/2);
	}
}