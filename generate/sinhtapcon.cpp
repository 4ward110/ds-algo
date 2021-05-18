#include <stdio.h>
#define MAX 100

int k,n,a[MAX],f[MAX];
void khoitao() {
	scanf("%d", &n);
	scanf("%d", &k);
}
void inkq() {
	int i;
	for(i = 1; i<=k; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Try(int i) {
	int j;
	for(j = 1; j <= n; j++) {
		if(f[j] == 0){
			a[i] = j;
			if(i == k) {
				inkq();
			}
			else{
				f[j] = 1;
				Try(i + 1);
			}
		}
	}
}




int main() {
	khoitao();
	Try(1);
	return 0;
}
