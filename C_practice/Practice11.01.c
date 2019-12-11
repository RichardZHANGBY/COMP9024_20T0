#include <stdio.h>

#define N 10

void max_min(int nums[], int n, int *max, int *min);

int main(int argc, char *argv[]) {
	int nums[10], max, min;
	
	printf("Enter %d numbers:", N);
	for (int i = 0; i < N; i++){
		scanf("%d", &nums[i]);
	}
	
	max_min(nums, N, &max, &min);
	
	printf("Largest: %d", max);
	printf("Smallest: %d", min);
}

void max_min(int nums[], int n, int *max, int *min){
	*max = *min = nums[0];
	for (int i = 1; i < n; i++){
		if (nums[i] > *max){
			*max = nums[i];
		}
		else if (nums[i] < *min){
			*min = nums[i];
		}
	}
}