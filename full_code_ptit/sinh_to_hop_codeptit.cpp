#include <stdio.h>
#define MAX 100


int ok = 0;
int t, n, k, a[100];

void khoitao() {
    scanf("%d", &n);
    scanf("%d", &k);
    for(int i = 1; i <= k; i++) {
        a[i] = i;
    }
}

void chht() {
    int i;
    for(i = 1; i <= k; i++) {
        printf("%d", a[i]);
    }
    printf(" ");
}

void sinhtiep() {
	int i = k;
	while(a[i] == n - k + i && i >= 0) {
		i--;
	}
	if(i == 0) {
		ok = 1;
	}
	else {
		a[i]++;
		for(int j = i + 1; j <= k; j++) {
			a[j] = a[i] + j - i;
		}
	}
}

int main() {
	scanf("%d", &t);
	while(t > 0) {
		khoitao();
		while(!ok) {
			chht();
			sinhtiep();
		}
		printf("\n");
		ok = 0;
		t--;
	}
	return 0;
}
