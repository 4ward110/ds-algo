#include <stdio.h>

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}



int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int left = low;
	int right = high - 1;
	while(true) {
		while(left <= right && arr[left] < pivot) left++;
		while(right >= left && arr[right] > pivot) right--;
		if(left = right) break;
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
	swap(arr[left], arr[high]);
	return left;
}

void quicksort(int arr[], int low, int high) {
	if(low < high) {
		int pi = partition(arr, low, high);
		quicksort(arr, low, pi-1);
		quicksort(arr, pi+1, high);
	}
}

void printarr(int arr[], int size) {
	int i;
	for(i = 0; i < size; i++) {
		printf("%d\t",arr[i]);
	}
}


int main() {
	int arr[] = {6,5,10,7,9,2,4};
	int n = sizeof(arr) / sizeof(arr[0]);
	quicksort(arr,0,n-1);
	printarr(arr,n);
//	partition(arr,0,n-1,n);
	return 0;
}
