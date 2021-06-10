#include <stdio.h>
#define MAX 100

int n,k,a[MAX],f[MAX];

void inkq() {
	int i;
	for(i = 1; i<=k; i++) {
		printf("%d",a[i]);
	}
	printf("\n");
}

void Try(int i) {
	int j;
	for(j = 1; j <=n; j++) {
		if(f[j] == 0){
			a[i] = j;
			if(i == k){
				inkq();
			}
			else{
				f[j] = 1;
				Try(i+1);
				f[j] = 0;
			}
		}
	}
}



int main() {
	scanf("%d%d", &n, &k);
	Try(1);
	return 0;
}
