#include <stdio.h>
#define MAX 100

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void hienmang(int m[], int n) {
	int i;
	for ( i = 0; i< n; i++) {
		printf("%d\t", m[i]);
	}
}

void selection(int m[], int &n) {
	int i,j;
	int min;
	for (i = 0; i < n-1; i++) {
		min = i;
		for( j = i + 1; j<n; j++) {
			if(m[min] > m[j]){
				min = j;
			}
		}
		if(min!=i){
			swap(m[min], m[i]);
		}
		printf("Buoc %d:\t", i + 1);
		hienmang(m,n);
		printf("\n");
	}
}



int main() {
	int i,n,m[MAX];
	scanf("%d",&n);
	for( i = 0; i<n; i++) {
		scanf("%d",&m[i]);
	}
	selection(m,n);
	return 0;
}
