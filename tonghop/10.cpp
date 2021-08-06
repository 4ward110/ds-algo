#include <stdio.h> 

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sinhtiep() {
	int a[1001];
	int i,n; 
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	i = n - 1;
	int k = n;
	while(a[i] > a[i + 1] && i >= 0) {
		i--;
	}
	if(i <= 0) {
		for(int i = 1; i <= n; i++) {
			printf("%d ", i);
		}
	}
	else {
		while(a[k] < a[i]) {
			k--;
		}
		swap(&a[k], &a[i]);
		int l = i + 1;
		int r = n;
		while(l < r) {
			swap(&a[l], &a[r]);
			l++;
			r--;
		}
		for(int i = 1; i <= n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	
}


int main() {
	int t;
	scanf("%d", &t);
	while(t > 0) {
		sinhtiep();
		t--;
	}
	return 0;
}
