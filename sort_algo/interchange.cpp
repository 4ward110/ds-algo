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


void interchange(int m[],int &n) {
	int i,j;
	for (i = 0; i < n-1; i++ ) {
		for(j = i+1; j < n; j++) {
			if(m[i] > m[j]) {
				swap(m[i],m[j]);
			}
		}
		printf("Buoc %d:\t", i + 1);
		hienmang(m,n);
		printf("\n");
	}
}

int main(){
	int n,i;
	scanf("%d",&n);
	int m[MAX];
	for( i = 0; i<n; i++) {
		scanf("%d",&m[i]);
	}
	interchange(m,n);
	return 0;
}
