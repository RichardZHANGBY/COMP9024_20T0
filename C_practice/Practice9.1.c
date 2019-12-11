#include <stdio.h>

void selection_sort(int a[], int n);

int main(int argc, char *argv[]) {
	int nums[30], i, nums_len;
	char ch;
	
	printf("Enter the list: ");
	for (nums_len = 0; (ch = getchar()) != '\n'; nums_len++){
		scanf(" %d", &nums[nums_len]);
	}
	
	for (i = 0; i < nums_len; i++){
		printf("%d ", nums[i]);
	}
	
	selection_sort(nums, nums_len);
	printf("\n");
	
	for (i = 0; i < nums_len; i++){
		printf("%d ", nums[i]);
	}
}

void selection_sort(int nums[], int n){
	int max = 0, tempnum;
	
	if (n == 0){
		return;
	}
	
	for (int i = 1; i < n; i++){
		if (nums[i] > nums[max]){
			max = i;
		}
	}
	
	tempnum = nums[max];
	nums[max] = nums[n-1];
	nums[n-1] = tempnum;
	
	selection_sort(nums, n-1);
}