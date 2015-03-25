#include <iostream>
#include <cstring>

using namespace std;

int dp[2000][2000];

char A[2000] = "acgdasda";
char B[2000] = "acgfdca";

int lcs(int a, int b) {
	if(a <= 0 || b <= 0) return 0;

	if(dp[a][b] != -1) {
		return dp[a][b];
	}

	if(A[a - 1] == B[b - 1]) {
		dp[a][b] = lcs(a - 1,b - 1) + 1;
	} else {
		dp[a][b] = max(lcs(a, b - 1), lcs(a - 1, b));
	}

	return dp[a][b];
}

void printLCS(int a, int b) {
	if(a == 0 || b == 0) return;

	if(A[a - 1] == A[b - 1]) {
		printLCS(a - 1, b - 1);
		cout << A[a - 1];
	} else if(dp[a][b] == dp[a - 1][b]) {
		printLCS(a - 1, b);
	} else {
		printLCS(a, b - 1);
	}
}

int main() {	
	for(int i = 0; i < 2000; i++) {
		for(int j = 0; j < 2000; j++) {
			dp[i][j] = -1;
		}
	}
	cout << lcs(strlen(A), strlen(B)) << endl;
	printLCS(strlen(A), strlen(B));
	cout << endl;
}