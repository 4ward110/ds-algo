#include <stdio.h>
#define MAX 100
int n,k,a[MAX];

void inkq() {
	int i;
	for(i = 1; i<=k; i++) {
		printf("%d",a[i]);
	}
	printf("\n");
}

void Try(int i) {
	int j;
	for(j = a[i-1]+1; j <= (n - k + i); j++) {
		a[i] = j;
		if(i == k) {
			inkq();
		}
		else{
			Try(i+1);
		}
	}
}


int main() {
	scanf("%d%d",&n,&k);
	Try(1);
	return 0;
	
}
