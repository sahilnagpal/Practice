#include <iostream>
#include <cmath>

using namespace std;

int fibWithMemoization(int a, int b, int num) {
	if(num == 0) return b;
	return fibWithMemoization(b, a + b, num - 1);
}

int fibNaive(int num) {
	if(num == 1 || num == 0) return 1;
	return fibNaive(num - 1) + fibNaive(num - 2);
}

int main() {
	int number = 6;
	cout << fibWithMemoization(0, 1, number) << endl;
	cout << fibNaive(number) << endl;
}