#include <stdio.h>

int t, n, a[9];
int ok = 0;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void khoitao() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		a[i] = i;
	}
}

void chht() {
	for(int i = 1; i <= n; i++) {
		printf("%d", a[i]);
	}
	printf(" ");
}

void sinhtiep() {
	int i = n - 1;
	int k = n;
	while(i>=0 && a[i] > a[i+1]) {
		i--;
	}
	if(i <= 0) {
		ok = 1;
	}
	else {
		while(a[k] < a[i]) {
			k--;
		}
		swap(a[k], a[i]);
		int l = i + 1;
		int r = n;
		while(l < r) {
			swap(a[l], a[r]);
			l++;
			r--;
		}
	}
}



int main() {
	scanf("%d", &t);
	while(t > 0) {
		khoitao();
		while(!ok) {
			chht();
			sinhtiep();
		}
		printf("\n");
		ok = 0;
		t--;
	}
	return 0;
}
