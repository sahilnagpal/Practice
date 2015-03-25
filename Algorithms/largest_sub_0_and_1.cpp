#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

void solve(int* a, int size) {
	int sum = 0, max_size = -1, start_index = 0;
	for(int i = 0; i < size - 1; i++) {
		if(a[i] == 0) sum = -1;
		else sum = 1;
		for(int j = i + 1; j < size; j++) {
			if(a[j] == 0) sum += -1;
			else sum += 1;
			
			if(sum == 0 && max_size < j - i + 1) {
				max_size = j - i + 1;
				start_index = i;
			}
		}
	}
	if(max_size != -1)
		cout << start_index << " to " << start_index + max_size - 1 << endl;
	else cout << "No Such SubArray" << endl;
}

void solveUsingExtraSpace(int* a, int size) {
	
	int* sumleft = new int[size];
	sumleft[0] = (a[0] == 0 ? -1 : 1);
	int min = sumleft[0], max = sumleft[0];
	
	for(int i = 1; i < size; i++) {
		sumleft[i] = sumleft[i - 1] + ((a[i] == 0) ? -1 : 1);
		if(min > sumleft[i]) min = sumleft[i];
		if(max < sumleft[i]) max = sumleft[i];
	}

	int* hash = new int[max - min + 1];
	for(int i = 0; i < max - min + 1; i++) hash[i] = -1;

	int max_size = -1, start_index = 0;
	for(int i = 0; i < size; i++) {
		if(sumleft[i] == 0) {
			max_size = i  + 1;
			start_index = 0;
		}

		if(hash[sumleft[i] - min] == -1) hash[sumleft[i] - min] = i;
		else {
			if((i - hash[sumleft[i] - min] ) > max_size) {
				max_size = i - hash[sumleft[i] - min];
				start_index = hash[sumleft[i] - min] + 1;
			}
		}
	}

	if(max_size == -1) {
		cout << "No such Sub Array" << endl;
	} else {
		cout << start_index << " to " << start_index + max_size - 1 << endl;
	}
}

int main() {
	int array[] = {1, 0, 1, 1, 1, 0, 0};
	int size = sizeof(array)/sizeof(int);
	solve(array, size);
	solveUsingExtraSpace(array, size);
}
