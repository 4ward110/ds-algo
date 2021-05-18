#include <stdio.h>
#define MAX 100 

int n,x[MAX];
void khoitao() {
	scanf("%d",&n);
}

void cauhinhhientai() {
	int i;
	for (i=1; i<=n; i++) {
		printf("%d",x[i]);
	}
	printf("\n");
}
//thuat toan quay lui
void Try(int i) {
	int j;
	for(j=0; j<=1; j++) {
		x[i] = j;
		if (i==n) cauhinhhientai();
		else Try(i+1);
	}
}

int main() {
	khoitao();
	Try(1);
	return 0;
}
