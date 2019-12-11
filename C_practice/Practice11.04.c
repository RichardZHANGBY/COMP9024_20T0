#include <stdio.h>

void swap(int *p, int *q);

int main(int argc, char *argv[]) {
	int a = 1, b = 2;
	
	swap(&a, &b);
	
	printf("%d,%d", a,b);
	
}

void swap(int *p, int *q){
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}