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

void bubble(int m[], int &n) {
	int i,j,kt;
	for (i = 0; i < n - 1; i++){
		kt = 0;
		for (j = 0; j < n - i - 1; j++){
			if(m[j] > m[j+1]){
				swap(m[j],m[1+j]);
				kt=1;
			}
		}
		if(kt==0) break;
		else {
			printf("Buoc %d: ",i + 1);
			hienmang(m,n);
			printf("\n");
		}
	}
}

int main() {
	int i,n,m[MAX];
	scanf("%d",&n);
	for( i = 0; i<n; i++) {
		scanf("%d",&m[i]);
	}
	bubble(m,n);

	return 0;
}
