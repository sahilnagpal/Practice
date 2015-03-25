#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void swap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void findNextMax(char digits[], int size) {
	int index = -1;
	for(int i = size - 1; i > 0; i--) {
		if(digits[i] > digits[i - 1] ) {
			index = i - 1;
			break;
		}
	}
	if(index == -1) {
		cout << "Not Possible" << endl;
		return;
	}
	int smallest = index + 1;
	for(int i = index + 1; i < size; i++) {
		if(digits[index] < digits[i] && digits[i] < digits[smallest]) {
			smallest = i;
		}
	}

	swap(&digits[index], &digits[smallest]);

	sort(digits + index + 1, digits + size);
	cout << "Next number with same set of digits is " << digits << endl;
 
    return;
}

int main() {
	char digits[100];
	cin >> digits;

	findNextMax(digits, strlen(digits));
}