#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[2005];

int count(int coins[], int index, int change) {
	if(change == 0) return 1;
	if(index == -1) return 0;
	if(change < 0) return 0;

	if(dp[index] != 0) return dp[index];
	
	dp[index] = count(coins, index, change - coins[index]) + count(coins, index - 1, change);
	return dp[index];
}

int main() {
	memset(dp, 0, sizeof(dp));
	
	int coins[] = {100, 50, 25, 1};
	int index = sizeof(coins)/sizeof(coins[0]) - 1;

	int change = 100;
	printf("Count: %d\n", count(coins, index, change));
}