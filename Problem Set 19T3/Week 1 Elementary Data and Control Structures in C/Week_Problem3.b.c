#include <stdio.h>

int fibonacci(int num);
void some_funciton(int num);

int main(int argc, char *argv[]) {
	for (int i = 1; i < 11; i ++){
		printf("Fib[%d] = %d\n%d\n", i, fibonacci(i), fibonacci(i));
		some_funciton(fibonacci(i));
	}
}

int fibonacci(int num){
	switch (num) {
		case 1:
		case 2:
			return 1;
		default:
			return fibonacci(num - 1) + fibonacci(num - 2);
	}
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