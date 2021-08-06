#include <stdio.h>

int ok = 0;
int cnt = 0;

void inkq(int a[], int x[], int n) {
	for(int i = 0;  i < n; i++) {
		if(a[i] == 1) {
			printf("%d\t",x[i]);
		}
	}
	printf("\n");
}

void sinhtiep(int a[], int n) {
	int t = n - 1;
	while(a[t] == 1 && t >= 0) {
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

int kiemtratong(int a[], int x[], int n, int s) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == 1) {
			sum = sum + x[i];
		}
	}
	if(sum == s) {
		cnt++;
		return 1;
	}
}

int main() {
	int n, s;
	scanf("%d %d", &n, &s);
	int a[n];
	int x[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	for(int i = 0;  i < n; i++) {
		a[i] = 0;
	}
	while(!ok) {
		if(kiemtratong(a, x, n, s) == 1) {
			inkq(a, x, n);
		}
		sinhtiep(a, n);
	}
	printf("%d\n", cnt);
	
	return 0;
}
