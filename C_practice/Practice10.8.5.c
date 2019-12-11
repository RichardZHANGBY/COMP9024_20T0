#include <stdio.h>

int main(void) {
	int fib_number[40] = {[0] = 0, [1] = 1};
	
	for (int i = 3; i < 40; i ++){
		fib_number[i] = fib_number[i-1] + fib_number[i-2];
		printf(" %d ", fib_number[i]);
	}
}