#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(int argc, char *argv[]) {
	int a[10] = {1, 56, 894, 84, 1235, 864514, 45, 12};
	int lar, seclar;
	
	find_two_largest(a, 10, &lar, &seclar);
	
	printf("lar:%d,seclar:%d", lar, seclar);
	
}

void find_two_largest(int a[], int n, int *largest, int *second_largest){
	if (a[0] > a[1]){
		*largest = a[0];
		*second_largest = a[1];
	}
	else{
		*largest = a[1];
		*second_largest = a[0];
	}
	
	for (int i = 2; i < n; i++){
		if (a[i] > *second_largest){
			if (a[i] > *largest){
				*second_largest = *largest;
				*largest = a[i];
			}
			else{
				*second_largest = a[i];
			}
		}
	}
}