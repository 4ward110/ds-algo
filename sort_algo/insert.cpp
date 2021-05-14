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
		printf("%d ", m[i]);
	}
}

void insert(int m[], int &n) {
	int i, key, j;
	int b[MAX];
	int count = 0;
	printf("Buoc 0: %d",m[0]);
	printf("\n");
	for (i = 1; i < n; i++) {
		key = m[i];
		j = i - 1;
		while(j >= 0 && key < m[j]){
			m[j+1] = m[j];
			j--;
			count++;
		}
		m[j+1] = key;
		printf("Buoc %d: ",i);
		hienmang(m,i+1);
		printf("\n");
	}
}

int main() {
	int i,n,m[MAX];
	scanf("%d",&n);
	for( i = 0; i<n; i++) {
		scanf("%d",&m[i]);
	}
	insert(m,n);
	
	return 0;
}
