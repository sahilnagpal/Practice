#include <iostream>
#include <climits>

using namespace std;

void mergeSort(int[], int, int);
void merge(int*, int, int, int);
void printArray(int*, int);

void mergeSort(int arr[], int start, int end) {
	if(start < end) {
		int mid = start + (end - start) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

void merge(int* arr, int start, int mid, int end) {
	//Size of the new Arrays to be constructed
	int first_size = mid - start + 1;
	int second_size = end - mid;

	//Create 2 arrays of the sizes mentioned above
	int* first_arr = new int[first_size + 1];
	int* second_arr = new int[second_size + 1];

 	//Copy the arr values to the corresponding arrays
	for(int i = 0; i < first_size; i++) first_arr[i] = arr[start + i];
	for(int i = 0; i < second_size; i++) second_arr[i] = arr[mid + i + 1];

	//Make their last Value to be INFINITY
	first_arr[first_size] = INT_MAX;
	second_arr[second_size] = INT_MAX;

	//Merge the 2 arrays now :P
	int i = 0, j = 0;
	for(int k = start; k <= end; k++) {
		if(first_arr[i] < second_arr[j])
			arr[k] = first_arr[i++];
		else
			arr[k] = second_arr[j++];
	}
}

void printArray(int* a, int size) {
	cout << "{ ";
	for(int i = 0; i < size - 1; i++) {
		cout << a[i] << ", "; 
	}
	cout << a[size - 1] << " }" << endl;
}

int main() {
	int arr[] = {10, 3, 5, 12, 23, 2, 1, 123, 67, 1}, size;
	size = sizeof(arr)/sizeof(int);
	mergeSort(arr, 0, size - 1);
	printArray(arr, size);
}