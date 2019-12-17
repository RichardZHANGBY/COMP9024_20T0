#include <stdio.h>
#include <stdbool.h>

bool check_backwards(int a, int b);

int main(int argc, char *argv[]) {
	for (int i = 10000; i < 25000; i++){
		if (check_backwards(i, 4*i)){
			printf("%d\n", i);
		}
	}
}

bool check_backwards(int a, int b){
	int div = 10000;
	while(a > 0){
		if (a % 10 != (b / div) % 10){
			return false;
		}
		a /= 10;
		div /= 10;
	}
	return true;
}