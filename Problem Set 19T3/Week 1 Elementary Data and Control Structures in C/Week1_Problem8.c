#include <stdio.h>

int max(int a, int b, int c);

int main(int argc, char *argv[]) {
	printf("The max number: %d", max(45, 813, 4));
}

int max(int a, int b, int c){
	return (a * (a > b) * (a > c) + b * (b > c) * (b > a) + c * (c > a) * (c > b));
}