#include <stdio.h>
#define MAX 100

int n,a[MAX],f[MAX];
void khoitao() {
	scanf("%d", &n);
}
void inkq() {
	int i;
	for(i = 1; i<=n; i++) {
		printf("%d", a[i]);
	}
	printf("\n");
}

void Try(int i) {
	int j;
	for(j = 1; j <= n; j++) {
		a[i] = j;
		if(i == n) inkq();
		else{

			Try(i + 1);

		}
	}
}




int main() {
	khoitao();
	Try(1);
	return 0;
}
