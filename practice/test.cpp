#include <stdio.h>
#define MAX 100

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}


int hienmang(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf(" %d ", a[i]);
	}
}

//int buble_sort(int a[], int n) {
//	int i, j, kt;
//	for( i = 0; i < n - 1 ; i++) {
//		kt = 0;
//		for( j = 0; j < n - i - 1; j++) {
//			if(a[j] > a[j + 1]) {
//				swap(a[j], a[j + 1]);
//				kt=1;
//			}
//		}
//		if (kt == 0) break;
//		printf("Buoc %d: ", i + 1);
//		hienmang(a,n);
//		printf("\n");
//	}
//}

//int interchange_sort(int a[], int n ){
//	int i, j;
//	for ( i = 0; i < n - 1; i++ ) {
//		for(j = i + 1; j < n; j++) {
//			if(a[i] > a[j]) {
//				swap(a[i], a[j]);
//			}
//		}
//	}	
//	
//}
//
//void selection(int a[], int &n) {
//	int i,j;
//	int min;
//	for (i = 0; i < n-1; i++) {
//		min = i;
//		for( j = i + 1; j<n; j++) {
//			if(a[min] > a[j]){
//				min = j;
//			}
//		}
//		if(min!=i){
//			swap(a[min], a[i]);
//		}
//		printf("Buoc %d:\t", i + 1);
//		hienmang(a,n);
//		printf("\n");
//	}
//}



//int insert_sort(int a[], int n) {
//	int i, k, j;
//	for(i = 1; i < n; i++) {
//		k = a[i];
//		j = i - 1;
//		while (j >= 0  && a[j] > k) {
//			a[j+1] = a[j];
//			j = j - 1;
//		}
//		a[j + 1] = k;
//	}
//}

int partition(int a[], int low, int high) {
	int pivot = a[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++) {
		if(a[j] <= pivot) {
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[high]);
	return (i+1);
}

void quickSort(int a[], int low, int high) {
	if(low < high) {
		int pi = partition(a, low, high);
		quickSort(a, low, pi - 1);
		quickSort(a, pi + 1, high);
	}
}




int main() {
	int i, n, a[MAX];
	scanf("%d", &n);
	
	for(i = 0; i<n; i++) {
		scanf("%d", &a[i]);
	}
//	hienmang(a,n);
//	buble_sort(a,n);
//	selection(a,n);
//	hienmang(a,n);
//	insert_sort(a,n);
	quickSort(a,0,n-1);
	hienmang(a,n);
	
	return 0;
}
