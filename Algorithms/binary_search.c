#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int low, int high, int key);
int pivotedBinarySearch(int arr[], int size, int key);
int findPivot(int arr[], int low, int high);

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int binarySearch(int arr[], int low, int high, int key) {
	int mid = low + (high - low) / 2;
	if(high < low) return -1;
	if(arr[mid] == key) return mid;

	if(arr[mid] > key) {
		return binarySearch(arr, low, mid - 1, key);
	} else return binarySearch(arr, mid + 1, high, key);
}

int pivotedBinarySearch(int arr[], int size, int key) {
	int pivot = findPivot(arr, 0, size - 1);

	if(pivot == -1) {
		return binarySearch(arr, 0, size - 1, key);
	}

	if(arr[pivot] == key) {
		return pivot;
	}
	if(arr[0] <= key) {
		return binarySearch(arr, 0, pivot - 1, key);
	} else {
		return binarySearch(arr, pivot + 1, size - 1, key);
	}
}

int findPivot(int arr[], int low, int high) {
	if(low > high) return -1;
	if(low == high) return low;

	int mid = low + (high - low)/2;
	if(mid < high && arr[mid] > arr[mid + 1]) {
		return mid;
	}
	if(mid > low && arr[mid] < arr[mid - 1]) {
		return mid - 1;
	}
	if(arr[low] >= arr[mid]) {
		return findPivot(arr, low, mid - 1);
	} else {
		return findPivot(arr, mid + 1, high);
	}
}

int main() {
	
	int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 12};
	int size = sizeof(arr)/sizeof(arr[0]);
	int a = pivotedBinarySearch(arr, size, 12);
	printf("%d\n", a);

	qsort(arr, size, sizeof(int), cmpfunc);
	a = binarySearch(arr, 0, size - 1, 1);
	printf("%d\n", a);

	return 0;
}