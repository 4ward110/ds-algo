#include <stdio.h>
#define MAX 100

int t,n,a[MAX],f[MAX];

void inkq() {
	int i;
	for(i = 1; i<=n; i++) {
		printf("%d",a[i]);
	}
	printf(" ");
}

void Try(int i) {
	int j;
	for(j = 1; j <=n; j++) {
		if(f[j] == 0){
			a[i] = j;
			if(i == n){
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
	scanf("%d", &t);
	while(t > 0) {
		scanf("%d",&n);
		Try(1);
		printf("\n");
		t--;
	}
	return 0;
}
