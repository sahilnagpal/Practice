#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int sum_array(int arr[], int size) {
	int curr_sum = 0, max_sum = INT_MIN, i;
	
	for(i = 0; i < size; i++) {
		curr_sum += arr[i];
		if(max_sum < curr_sum) {
			max_sum = curr_sum;
		}
		if(curr_sum < 0) {
			curr_sum = 0;
		}
	}
	return max_sum;
}

int main() {
	int arr[] = {-2, -3, -1, -2, -3};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("%d\n", sum_array(arr, size));
}