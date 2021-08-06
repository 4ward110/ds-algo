#include <stdio.h>


int ok = 0;

void inkq(int a[], int n) {
	for(int i = 0;  i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void sinhtiep(int a[], int n) {
	int t = n - 1;
	while(a[t] == 1 && t >=0 ) {
		a[t] = 0;
		t--;
	}
	if(t < 0) {
		ok = 1;
	}
	else {
		a[t] = 1;
	}
}

int kttn(int a[], int n) {
	int l = 0;
	int r = n - 1;
	while(l < r) {
		if(a[l] != a[r])
		return 0;
		l++;
		r--;
	}
	return 1;
}


int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0;  i < n; i++) {
		a[i] = 0;
	}
	while(!ok) {
		if(kttn(a, n) == 1) {
			inkq(a, n);
		}
		sinhtiep(a, n);		
	}
	return 0;
}
