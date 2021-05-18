#include<stdio.h>
#define MAX 100
int n, x[MAX], f[MAX];
void khoitao() {
	scanf("%d", &n);
}

void chht() {
	int i;
	for(i =1; i<=n; i++) {
		printf("%d", x[i]);
	}
	printf("\n");
}
void Try(int i) {
	int j;
	for (j=1; j<=n; j++) {
		if (f[j] == 0) {
			x[i] = j;
			if(i == n) chht();
			else{
				f[j] = 1;
				Try(i+1);
				f[j] = 0;
			}
		}
	}
}

int main() {
	khoitao();
	Try(1);
	return 0;
}
