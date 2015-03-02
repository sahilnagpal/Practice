#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int dp[2005];

int lis(int a[], int size) {
	int i = 0, j = 0, largest = INT_MIN;
	for(i = 0; i < size; i++) {
		for(j = 0; j < i; j++) {
			if(a[i] > a[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	for(i = 0; i < size; i++) {
		if(largest < dp[i]) largest = dp[i];
	}
	return largest;
}

int main() {
	int array[] = {1, -3, -2, 4, 5};
	int size = sizeof(array)/ sizeof(array[0]), i;
	for(i = 0; i < size; i++) {
		dp[i] = 1;
	}
	int result = lis(array, size);

	printf("%d\n", result);
}