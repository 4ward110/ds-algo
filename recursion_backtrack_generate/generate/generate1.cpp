// sinh nhi phan
#include <stdio.h>
#define MAX 100

int n,a[MAX],ok = 0;

void khoitao() {
	int i;
	scanf("%d", &n);
	for(i = 0; i<n; i++) {
		a[i] = 0;
	}
}

void chht() {
	int i;
	for(i = 0; i < n; i++) {
		printf("%d",a[i]);
	}
	printf("\n");
}

void sinhketiep() {
	int i = n - 1;
	while(a[i] == 1 && i>= 0) {
		i--;
	}
	if(i == -1) {
		ok = 1;
	}
	else {
		a[i] = 1;
		int j;
		for(j = 1 + i; j < n; j++) {
			a[j] = 0;
		}
	}
}


int main() {
	khoitao();
	while(!ok) {
		chht();
		sinhketiep();
	}
	return 0;
}
