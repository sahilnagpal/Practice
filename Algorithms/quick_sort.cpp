#include <iostream>

using namespace std;

void inline swap(int* a, int start, int end);
int partition(int* a, int start, int end);
void quickSort(int* a, int start, int end); 
void printArray(int* a, int size);

void quickSort(int* a, int start, int end) {
	int pivot = 0;
	if(start < end) {
		pivot = partition(a, start, end);
		quickSort(a, start, pivot - 1);
		quickSort(a, pivot + 1, end);
	}
}

int partition(int* a, int start, int end) {
	int left = start, right = end, pivot_value = a[start];

	while(left < right) {
		while(a[left] <= pivot_value)
			left++;
		
		while(a[right] > pivot_value)
			right--;

		if(left < right)
			swap(a, left, right);
	}

	a[start] = a[right];
	a[right] = pivot_value;
	return right;
}

void inline swap(int* a, int left, int right) {
	int temp = a[left];
	a[left] = a[right];
	a[right] = temp;
}

void printArray(int* a, int size) {
	cout << "{";
	for(int i = 0; i < size - 1; i++) {
		cout << a[i] << ", "; 
	}
	cout << a[size - 1] << "}" << endl;
}

int main() {
	int a[] = { 6, 10, 13, 5, 8, 3, 2, 11}, size;
	size = sizeof(a) / sizeof(int);
	quickSort(a, 0, size - 1);
	printArray(a, size);
}