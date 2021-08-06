#include <stdio.h>

int ok = 0;

void sinhtiep(char a[], int n) {
	int t = n - 1;
	while(t >= 0 && a[t] == 'B') {
		a[t] = 'A';
		t--;
	}
	if(t == -1) {
		ok = 1;
	}
	else {
		a[t] = 'B';
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t > 0) {
		int n;
		scanf("%d", &n);
		char a[n];
		for(int i = 0; i < n; i++) {
			a[i] = 'A';	
		}
		while(!ok) {
			for(int i = 0; i < n; i++) {
				printf("%c", a[i]);	
			}
			printf(" ");
			sinhtiep(a, n);
		}
		ok = 0;
		printf("\n");
		t--;
	}
	return 0;
}
