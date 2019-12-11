#include <stdio.h>

void find_two_largest(const int *a, int n, int *largest, int *second_largest);

int main(int argc, char *argv[]) {
	
	int larest = 0, seclar = 0;
	int a[10] = {1,2,3,4,5,7,8,9,6,10};
	
	find_two_largest(a, 10, &larest, &seclar);
	printf("%d,%d", larest, seclar);
	
}

void find_two_largest(const int *a, int n, int *largest, int *second_largest){
	for (const int *p = a; p < a + n; p++){
		if (*p > *second_largest){
			if (*p > *largest){
				*second_largest = *largest;
				*largest = *p;
			}
			else{
				*second_largest = *p;
			}
		}
	}
}