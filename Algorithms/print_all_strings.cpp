#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

void swap(char* x, char* y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}

void printPermutations(char str[], int i, int size) {
	if(i == size) {
		cout << str << endl;
	}
	else {
		for(int j = i; j <= size; j++) {
			swap( (str + i), (str + j));
			printPermutations(str, i + 1, size);
			swap((str + i), (str + j));
		}
	}
}

int main() {
	char str[100] = "hat";
	printPermutations(str, 0, strlen(str) - 1);
}