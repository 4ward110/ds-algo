#include <stdio.h>
#define MAX 100

int n,k,a[MAX],ok=0;

void khoitao() {
	scanf("%d%d",&n,&k);
	int i;
	for (i = 1; i<=k; i++) {
		a[i] = i;
	}
}

void chht() {
	int i;
	for( i = 1; i<=k; i++ ) {
		printf("%d",a[i]);
	}
	printf("\t");
}

void sinhtiep() {
	int i = k;
	while(i > 0 && a[i] == n-k+i) {
		i--;
	}
	if(i == 0) ok = 1;
	else {
		a[i]++;
		int j;
		for(j = i + 1; j<=k; j++) {
			a[j] = a[i] + j - i;
		}
	}
} 


int main() {
	khoitao();
	while(!ok) {
		chht();
		sinhtiep();
	}
	return 0;	
}
