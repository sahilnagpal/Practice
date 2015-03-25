#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

void solve(int array[], int size, int diff) {
	map<int, int> m;
	for(int i = 0; i < size; i++) {
		m[array[i]] = 1;
	}
	
	int sub, add, count = 0;
	for(int i = 0; i < size; i++) {
		sub = array[i] - diff;
		
		if(m.find(sub) != m.end()) {
			count++;
			cout << "(" << array[i] << ", " << sub << ")" << endl;
		}
		
		add = array[i] + diff;
		if(m.find(add) != m.end() ) {
			count++;
			cout << "(" << array[i] << ", " << add << ")" << endl;
		}
		m.erase(m.find(array[i]));
	}

	cout << count << endl;
}

int cmpFunc(const void* a, const void* b) {
	return ( *(int*)a - *(int*)b ); 
}

void solveWithSorting(int* a, int size, int diff) {
	int l = 0, r = 1, count = 0;
	while(r < size) {
		if(a[r] - a[l] == diff) {
			count++;
			cout << "(" << a[r] << ", " << a[l] << ")" << endl;
			l++;
			r++;
		}
		else if(a[r] - a[l] < diff) {
			r++;
		} else {
			l++;
		}
	}

	cout << count << endl;

}

int main() {
	int arr[] = {7,23,19,10,11,9,3,15, 6};
	int size = sizeof(arr)/sizeof(arr[0]);
	int k = 4;
	solve(arr, size, k);
	qsort(arr, size, sizeof(int), cmpFunc);
	solveWithSorting(arr, size, k);
}